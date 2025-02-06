import QtQuick 2.15
import QtQuick.Controls 2.15
import Components

Rectangle {
    id: gateIcon
    width: 40
    height: 40
    border.width: 0
    radius: 3
    scale: (mouseArea.pressed || gateIcon.Drag.active) ? 1.1 : 1

    property alias iconSource: iconImage.source
    property string gateType: "Default"
    property bool isInteractive: gateType !== "Identity"
    property bool fromPalette
    property var grid

    signal leftClicked()
    signal rightClicked()
    signal createFloatingIcon()

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
                gateIcon.leftClicked();
            } else if (mouse.button === Qt.RightButton) {
                gateIcon.rightClicked();
            }
        }

        onPressed: {
            if (!isInteractive) return;
            // drag.target: floatingIcon
            gateIcon.createFloatingIcon();
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