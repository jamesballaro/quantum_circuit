import QtQuick 2.15

Image {
    id: floatingIcon
    width: 30
    height: 50
    source: ""
    visible: false
    z: 200

    property string gateType
    property var parentGrid
    property bool isDragging: false
    property real startX: 0
    property real startY: 0

    function startDragging(iconSource, type, initialX, initialY) {
        console.log("Floating icon initialized at:", initialX, initialY);
        source = iconSource;
        gateType = type;
        startX = initialX;
        startY = initialY;
        x = startX;
        y = startY;
        visible = true;
        isDragging = true;

        // Start dragging immediately
        mouseArea.forceActiveFocus();
        mouseArea.drag.start(); 
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        drag.target: floatingIcon
        cursorShape: Qt.ClosedHandCursor
        
        onReleased: {
            floatingIcon.isDragging = false;

            let localPos = circuitGrid.mapFromItem(floatingIcon.parent, floatingIcon.x, floatingIcon.y);
            let snapPosition = circuitGrid.getClosestCell(localPos.x, localPos.y);

            if (snapPosition) {
                let newPos = floatingIcon.parent.mapFromItem(circuitGrid, snapPosition.x, snapPosition.y);
                
                // Insert gate into model
                gateModel.insertGate(gateType, snapPosition.j, snapPosition.i);
                console.log("Placed gate:", gateType, "at", snapPosition.i, snapPosition.j);
            } else {
                console.log("Invalid drop: Destroying floating icon", gateType);
            }

            floatingIcon.visible = false;
        }
    }
}