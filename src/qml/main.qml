import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import Components 1.0
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import Components 1.0

ApplicationWindow {
    id : root
    visible: true
    width: 800
    height: 640
    color: "#F8F8FD"

    Shortcut {
        sequence: "Ctrl+R"
        onActivated: {
            console.log("Hot-reload activated!")
            qgui.loadQml()
        }
    }

    Control {
        id: control
        anchors.fill: parent
        font.bold: true
        font.family: "Trebuchet MS"

        Rectangle {
            id: columnr
            width: 220
            height: root.height
            border.color: "black"
            border.width: 2
            color: "#F8F8FD"
            }

        Rectangle {
            id: rowr
            width: root.width
            height: 60
            border.color: "black"
            border.width: 2
            color: "#F8F8FD"
        }
        Rectangle {
            id: gridr
            width: columnr
            height: root.height*0.5
            border.color: "black"
            border.width: 5
            color: "#F8F8FD"

            anchors.right: columnr.right
            anchors.rightMargin: 40 // Adds a 10-pixel offset
            anchors.top: rowr.bottom
            anchors.topMargin: 40 // Adds spacing from the top bar
        }


       ColumnLayout {
            property int topPadding: 10
            property int leftPadding: 25
            focus: true 
            id:maincol

            Component.onCompleted: {
                qgui.launch()
            }
            
            
            Text { //Title
                text: "qCircuit GUI ＊ "
                font.pixelSize: 30
                font.family: "Trebuchet MS"
                font.bold: true
                color: "blue"
                // horizontalAlignment: Text.AlignLeft
                topPadding: parent.topPadding
                leftPadding: parent.leftPadding
            }
            Text { //"Gates"
                text: "Gates "
                font.pixelSize: 20
                font.family: "Trebuchet MS"
                font.bold: true
                color: "blue"
                horizontalAlignment: Text.AlignLeft
                topPadding: 20
                leftPadding: parent.leftPadding
            }

            Grid {
                leftPadding: parent.leftPadding
                id: iconGrid
                columns: 3
                spacing: 10
                ListModel {
                    id: gateModel
                    ListElement { iconSource: "qrc:/qml/icons/hadamard.png"; gateType: "Hadamard" }
                    ListElement { iconSource: "qrc:/qml/icons/cnot.png"; gateType: "CNOT" }
                    ListElement { iconSource: "qrc:/qml/icons/cz.png"; gateType: "CZ" }
                    ListElement { iconSource: "qrc:/qml/icons/swap.png"; gateType: "Swap" }
                    ListElement { iconSource: "qrc:/qml/icons/toffoli.png"; gateType: "Toffoli" }
                    ListElement { iconSource: "qrc:/qml/icons/phase.png"; gateType: "Phase" }
                    ListElement { iconSource: "qrc:/qml/icons/pauli_x.png"; gateType: "Pauli-X" }
                    ListElement { iconSource: "qrc:/qml/icons/pauli_y.png"; gateType: "Pauli-Y" }
                    ListElement { iconSource: "qrc:/qml/icons/pauli_z.png"; gateType: "Pauli-Z" }
                }

                Repeater {
                    model: gateModel
                    GateIcon {
                        iconSource: model.iconSource
                        property string gateType: model.gateType

                        Connections {
                            target: model
                            function leftClicked() {
                                console.log("Gate type " + gateType + " left-clicked")
                                // qgui.handleLeftClick(gateType)
                            }
                            function rightClicked() {
                                console.log("Gate type " + gateType + " right-clicked")
                                // qgui.handleRightClick(gateType)
                            }
                        }
                    }
                }
            }

            Column{
                id: buttonGroup
                topPadding: root.height - 400

                PButton { //Save Circuit
                    id: save
                    // topPadding: 60
                    // leftPadding: 0
                    prefix: "＊"
                    pbuttontext: "Save Circuit"
                    // anchors.right: parent.right            
                }
                PButton { //Load Circuit
                    id: load
                    // topPadding: 60
                    // leftPadding: 0
                    prefix: "＊"
                    pbuttontext: "Load Circuit"
                    Layout.fillHeight: true
                }
                PButton { //Exit
                    id: exit
                    // topPadding: 60
                    // la
                    // leftPadding: 0
                    prefix: "＊"
                    pbuttontext: "Exit"
                    // anchors.bottom: columnr.bottom
                
                }
            }
        }
    }
}