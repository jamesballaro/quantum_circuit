import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: pButton

    property string prefix: "＊" 
    property string name: "Default Text"  
    width: 185

    hoverEnabled: true

    contentItem: Text {  
        text: pButton.prefix + " " + pButton.name
        font: pButton.font
        color: pButton.down ? "white" : (pButton.hovered ? "darkblue" : "blue")
    }
    
    background: Rectangle {
        color: pButton.down ? "royalblue" : (pButton.hovered ? "#DDEEFF" : "#F8F8FD") 
        border.color: pButton.down ? "blue" : "blue"
        border.width: 1.5
        radius: 5

        anchors.verticalCenter: contentItem.verticalCenter
        anchors.top: contentItem.top
        anchors.left: contentItem.left
        anchors.margins:-5
        width: parent.width

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onClicked: pButton.clicked // Preserve the built-in Button `onClicked` behavior
        }
    }
}