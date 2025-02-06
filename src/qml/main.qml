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
    ListModel {
        id: gates
        ListElement { iconSource: "qrc:/qml/icons/hadamard.png"; gateType: "Hadamard"}
        ListElement { iconSource: "qrc:/qml/icons/cnot.png"; gateType: "CNOT" }
        ListElement { iconSource: "qrc:/qml/icons/cz.png"; gateType: "CZ" }
        ListElement { iconSource: "qrc:/qml/icons/swap.png"; gateType: "Swap" }
        ListElement { iconSource: "qrc:/qml/icons/toffoli.png"; gateType: "Toffoli" }
        ListElement { iconSource: "qrc:/qml/icons/phase.png"; gateType: "Phase" }
        ListElement { iconSource: "qrc:/qml/icons/pauli_x.png"; gateType: "PauliX" }
        ListElement { iconSource: "qrc:/qml/icons/pauli_y.png"; gateType: "PauliY" }
        ListElement { iconSource: "qrc:/qml/icons/pauli_z.png"; gateType: "PauliZ" }
        ListElement { iconSource: ""; gateType: "Identity" }
    }
    Component {
        id: gateComponent
        GateIcon {
            gateType: "Default"
            iconSource: ""
        }
    }
    
    FloatingIcon {
        id: floatingGateIcon
    }

    Connections {
        target: gateModel
        function onDataChanged() {
            circuitGrid.model = null;  // Detach model temporarily
            circuitGrid.model = gateModel; // Reattach model
            circuitGrid.forceLayout();  // Forces re-rendering
            console.log("Circuit updated, refreshing UI...");
            console.log("");
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
        Rectangle {
            id: main
            width: root.width-220
            height: root.height-60
            border.color: "#d2d2d2"
            border.width: 2
            anchors.left: columnr.right
            anchors.top: rowr.bottom
            anchors.bottom: root.bottom
            color: "#eaeaea"

            TableView {
                id: circuitGrid
                width: parent.width * 0.6  
                height: parent.height * 0.6
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 100
                anchors.leftMargin: 75
                columnSpacing: 80
                clip: false

                model: gateModel ? gateModel : null
                
                property int nrows: model ? model.rowCount() : 2
                property int ncols: model ? model.columnCount() : 2
                property int cellWidth: 60
                property int cellHeight: 40

                function getClosestCell(dropX, dropY) {

                    let cellX = Math.round(dropX / cellWidth) 
                    let cellY = Math.round(dropY / cellHeight)
                    
                    let gridX = cellX * cellWidth;
                    let gridY = cellY * cellHeight;

                    // console.log("gridx,y",gridX,gridY)

                    if (gridX >= cellWidth && gridX < (ncols+1) * cellWidth && gridY >= 0 && gridY < nrows * cellHeight) {
                        return { x: gridX, y: gridY , i: cellX, j: cellY};

                    }
                    return null;
                }

                Component {
                    id: textDelegate
                    BitButton {
                        implicitWidth: 60
                        implicitHeight: 40
                        isRemovable: nrows > 2
                    }
                }

                Component {
                    id: gateDelegate
                    GateIcon {
                        implicitWidth: 40
                        implicitHeight: 40
                        gateType: type
                        iconSource: find(gates,gateType)
                        color: "transparent"
                        fromPalette: false

                        function find(list, search) {
                            for(var i = 0; i < list.count; ++i) {
                                if (list.get(i).gateType === search) 
                                    return list.get(i).iconSource
                            }
                        }
                    }
                }

                delegate: Item {
                    id: delegateItem
                    implicitWidth:  delegateLoader.implicitWidth
                    implicitHeight: delegateLoader.implicitHeight
                    Loader {
                        id: delegateLoader
                        anchors.fill: parent

                        Component.onCompleted:{
                            console.log("loader:",model.gateType,"at",row,column) 
                        }

                        property string type : model.gateType
                        property int row : model.row
                        property int column : model.column
                        property int nrows: circuitGrid.nrows

                        sourceComponent: (model.gateType === "Qubit" || model.gateType === "ClassicalBit") ? textDelegate : gateDelegate

                    }
                }
            }
        }


       ColumnLayout {
            property int topPadding: 10
            property int leftPadding: 25
            focus: true 
            id: maincol
            
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

                Repeater {
                    model: gates
                    GateIcon {
                        id: gridIcon
                        iconSource: model.iconSource
                        gateType: model.gateType
                        color: "transparent"
                        fromPalette:true

                        onLeftClicked: {
                            console.log("left-clicked " + gateType)
                            // qgui.handleLeftClick(gateType)
                        }
                        onRightClicked:{
                            console.log("right-clicked" + gateType )
                            // qgui.handleRightClick(gateType)
                        }
                        onCreateFloatingIcon: {
                            let globalPos = gridIcon.mapToItem(root.contentItem, 0, 0);
                            floatingGateIcon.startDragging(iconSource, gateType, globalPos.x, globalPos.y);
                        }
                    }
                }
            }
            Column{
                id: buttonGroup
                topPadding: root.height - 450
                // property int buttonWidth: 185

                PButton { //Save Circuit
                    id: save
                    prefix: "＊"
                    name: "Save Circuit"
                    anchors.right: parent.right           
                    onClicked:{
                        console.log("Circuit saved")
                    }
                }
                PButton { //Load Circuit
                    id: load
                    // topPadding: 60
                    // leftPadding: 0
                    prefix: "＊"
                    name: "Load Circuit"
                    Layout.fillHeight: true
                    onClicked: {
                        console.log("Circuit Loaded")
                    }
                }
                PButton { //Exit
                    id: exit
                    prefix: "＊"
                    name: "Exit"
                    onClicked:{
                        console.log("Exited")
                        Qt.quit()
                    }
                
                }
            }
        }
    }
}

// Component.onCompleted: {
//     console.log("QML: qgui is", qgui);
//     console.log("model is",model);
//     if (qgui !== null) {
//         console.log("QML: qgui.gateModel is", qgui.gateModel);
//         if (qgui.gateModel === null) {
//             console.error("ERROR: gateModel is null!");
//         } else {
//             console.log("SUCCESS: gateModel is assigned.");
//         }
//     } else {
//         console.error("ERROR: qgui is null!");
//     }
// }

                