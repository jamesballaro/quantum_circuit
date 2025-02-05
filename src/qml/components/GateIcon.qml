import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: gateIcon

    width: 40
    height: 40
    border.width: 2
    radius: 3

    border.color: (mouseArea.pressed || gateIcon.Drag.active) ? "black" : "transparent"
    scale: (mouseArea.pressed || gateIcon.Drag.active) ? 1.1 : 1

    signal leftClicked()
    signal rightClicked()
    // signal gateSnapped()

    property alias iconSource: iconImage.source
    property string gateType: "Default"
    property bool isInteractive: gateType !== "Identity"
    property bool fromPalette
    property var grid

    Drag.active: isInteractive && mouseArea.pressed
    Drag.hotSpot.x: width / 2
    Drag.hotSpot.y: height / 2
    Drag.source: gateIcon

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: isInteractive 
        hoverEnabled: isInteractive
        cursorShape: isInteractive ? (mouseArea.pressed ? Qt.ClosedHandCursor : Qt.PointingHandCursor) : Qt.ArrowCursor
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: mouse => {
            if (!isInteractive) return;
            if (mouse.button === Qt.LeftButton) {
                console.log("Left clicked on", gateIcon.gateType);
                gateIcon.leftClicked();
            } else if (mouse.button === Qt.RightButton) {
                console.log("Right clicked on", gateIcon.gateType);
                gateIcon.rightClicked();
            }
        }

        drag.target: isInteractive ? parent : undefined

        onPressed: {
            if (!isInteractive) return;
            gateIcon.Drag.active = true;
            cursorShape = Qt.ClosedHandCursor;
        }

        onReleased: {
            if (!isInteractive) return;
            gateIcon.Drag.active = false;
            cursorShape = Qt.PointingHandCursor; // Reset cursor on release

            gateIcon.grid = gateIcon.fromPalette ? iconGrid : circuitGrid

            let localPos = circuitGrid.mapFromItem(gateIcon.grid, gateIcon.x, gateIcon.y);
            let snapPosition = circuitGrid.getClosestCell(localPos.x, localPos.y); 

            if (snapPosition) {
                let newPos = gateIcon.grid.mapFromItem(circuitGrid,snapPosition.x,snapPosition.y)

                // console.log("new",newPos);    
                gateIcon.x = newPos.x;
                gateIcon.y = newPos.y;
                // console.log("row,col",row,column)

                let rowIndex = fromPalette? snapPosition.i : row
                let colIndex = fromPalette? snapPosition.j : column

                gateModel.insertGate(gateType,rowIndex,colIndex);
                // gateIcon.fromPalette = false;
            } else {
                // let newPos = grid.mapFromItem(circuitGrid,snapPosition.x,snapPosition.y)
                // console.log("new",newPos);   
                // console.log("localPos",localPos);  
                console.log("Invalid drop: destroyed gate",gateIcon.gateType);
                    gateIcon.destroy();
                if (fromPalette) {
                    iconGrid.createGateIcon(gateType, iconSource);
                }
            }
        }
    }

    Image {
        id: iconImage
        anchors.centerIn: parent
        width: parent.width * 0.9
        height: parent.height * 0.9
        visible: source !== ""
        fillMode: Image.PreserveAspectFit

        onStatusChanged: {
            if (status === Image.Error) {
                console.log("Failed to load image:", source);
                source = "qrc:qml/icons/default.png";
            }
        }
    }
}