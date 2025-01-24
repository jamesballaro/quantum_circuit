import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick 2.15

Rectangle {
    id: gateIcon

    width: 40
    height: 40
    border.color: mouseArea.containsMouse ? "black" : "#F8F8FD"
    border.width: 2 // Keep the border width fixed
    radius: 3
    scale: mouseArea.containsMouse ? 1.1 : 1 // Use scale for hover effect

    signal leftClicked()
    signal rightClicked()

    property alias iconSource: iconImage.source

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: mouse => {
            if (mouse.button === Qt.LeftButton) {
                console.log("Left button clicked on", gateIcon.gateType);
                gateIcon.leftClicked();
            } else if (mouse.button === Qt.RightButton) {
                console.log("Right button clicked on:", gateIcon.gateType);
                gateIcon.rightClicked();
            }
        }
    }

    Image {
        id: iconImage
        anchors.centerIn: parent
        width: parent.width * 0.9 // Scale image relative to Rectangle size
        height: parent.height * 0.9
        source: ""
        fillMode: Image.PreserveAspectFit // Maintain aspect ratio

        onStatusChanged: {
            if (status === Image.Error) {
                console.log("Failed to load image:", source);
                source = "icons/default.png"; // Fallback to default image
            }
        }
    }
}