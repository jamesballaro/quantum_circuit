import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: pbutton
    property string prefix: "＊"  // Default prefix
    property string pbuttontext: "Default Text"  // Default button text
    // padding: -10
    text: prefix + " " + pbuttontext


    contentItem: Text {
        text: pbutton.text
        font: pbutton.font
        // opacity: pbutton.enabled ? 1.0 : 0.5
        color: pbutton.down ? "white" : "blue"

    }

    background: Rectangle {
        color: pbutton.down ? "royalblue" : "#F8F8FD"
        border.color: pbutton.down ? "blue" : "blue"
        border.width: 1.5
        radius: 5
        // anchors.horizontalCenter: contentItem.horizontalCenter
        anchors.verticalCenter: contentItem.verticalCenter
        anchors.top: contentItem.top
        anchors.left: contentItem.left
        anchors.margins:-5
        width: 185
        
    }


    // Focus for keyboard navigation
    // focus: true
    // Keys.onReturnPressed: pbutton.clicked()

    // Accessibility
    // Accessible.name: pbutton.text
}