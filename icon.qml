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
    signal onDestroyed()

    property alias iconSource: iconImage.source
    property string gateType: "Default"
    property var grid: circuitGrid
    property bool dropped: false
    property bool isInteractive: gateType !== "Identity"
    property bool fromPalette: false  // Indicates if this icon originated from the selection palette

    Drag.active: isInteractive && mouseArea.pressed
    Drag.hotSpot.x: width / 2
    Drag.hotSpot.y: height / 2
    Drag.source: gateIcon

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: isInteractive 
        hoverEnabled: true
        cursorShape: isInteractive ? ((mouseArea.pressed || gateIcon.Drag.active) ? Qt.ClosedHandCursor : Qt.PointingHandCursor) : Qt.ArrowCursor
        acceptedButtons: isInteractive ? (Qt.LeftButton | Qt.RightButton) : Qt.NoButton

        onClicked: mouse => {
            if (!isInteractive) return;
            if (mouse.button === Qt.LeftButton) {
                console.log("Left button clicked on", gateIcon.gateType);
                gateIcon.leftClicked();
            } else if (mouse.button === Qt.RightButton) {
                console.log("Right button clicked on", gateIcon.gateType);
                gateIcon.rightClicked();
            }
        }

        drag.target: isInteractive ? parent : undefined

        onPressed: {
            if (!isInteractive) return;
            gateIcon.Drag.active = true;
            console.log("Dragging", gateIcon.gateType);

            if (fromPalette) {
                iconGrid.createGateIcon(gateType, iconSource);
            }
        }

        onReleased: {
            if (!isInteractive) return;
            gateIcon.Drag.active = false;
            console.log("Released", gateIcon.gateType);
            cursorShape = isInteractive ? Qt.PointingHandCursor : Qt.ArrowCursor;
        }
    }

    onDropped: {
        if (!isInteractive) return;

        let snapPosition = grid.getClosestCell(x, y);  // Find nearest grid cell
        if (snapPosition) {
            console.log("Snapping to grid at:", snapPosition.x, snapPosition.y);
            x = snapPosition.x;
            y = snapPosition.y;
        } else {
            console.log("Dropping outside the grid. Deleting gateIcon.");
            parent.removeGate(gateIcon);
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