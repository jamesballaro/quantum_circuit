import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: bitButton
    width: 100; height: 40

    property string type: "Qubit"
    property bool isRemovable

    // Signals to notify the main QML file when options are selected
    signal addOptionSelected()
    signal infoOptionSelected()
    signal removeOptionSelected()

    color: "transparent"
    border.width: 2
    radius: 0
    border.color: mouseArea.pressed ? "black" : (mouseArea.containsMouse ? "grey" : "transparent" )

    Text {
        id: rowLabel
        font.family: "Menlo"
        font.pixelSize: 18
        anchors.centerIn: parent
        color: "black"
        // Compute label text based on type and row
        property string bitText: type === "Qubit" ? "q" : "c"
        text: bitText + "[" + row + "]"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        enabled: true
        hoverEnabled: true
        cursorShape: pressed ? Qt.ClosedHandCursor : Qt.PointingHandCursor
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: mouse => {
            if (mouse.button === Qt.LeftButton) {
                // Call leftClicked() when the left button is clicked
                bitButton.rightClicked();
            } else 
            
            if (mouse.button === Qt.RightButton) {
                console.log("Right clicked on", type);
                bitButton.rightClicked();
                // (Optional: Handle right-click actions)
            }
        }

        onPressed: {
            cursorShape = Qt.ClosedHandCursor;
        }

        onReleased: {
            cursorShape = Qt.PointingHandCursor; // Reset cursor on release
        }
    }

    Menu {
        id: dropdownMenu
        width: 100
        font.family: "Menlo"
        font.pixelSize: 15


        MenuItem {
            text: "Add"
            onTriggered: {
                gateModel.addBitRow();
            }
        }
        MenuItem {
            enabled: isRemovable
            text: "Remove"
            onTriggered: {
                gateModel.removeBitRow();
            }
        }

        MenuItem {
            text: "Info"
            onTriggered: {
                // HANDLE GATEMODEL.GETINFO
            }
        }
    }

    // The leftClicked function opens the dropdown menu.
    function rightClicked() {
        dropdownMenu.popup(bitButton.x, bitButton.y + height);
    }
}