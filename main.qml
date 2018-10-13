import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import ru.fo.core 1.0
import QtCharts 2.2

Window {
    id: main
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//    property list items
    property Core core: Core{

    }


    Switch {
        id: switchEdit
        text: "Редактировать"
    }

    Rectangle {
        id: waveTank
        width: parent.width * 0.7
        height: parent.height * 0.4
        anchors.centerIn: parent
        border.color: "black"
        border.width: 2

        Canvas {
            id: waveCanvas
            anchors.fill: parent
            onPaint: {
                var ctx = getContext('2d')
                ctx.lineWidth = 3
                ctx.strokeStyle = "#37474f"
                ctx.beginPath()
                ctx.moveTo(0, waveTank.height / 2);
                var minIndex = 0
                console.log(core.countListXposition(), core.countListYposition())
                if(core.countListXposition() === core.countListYposition())
                    minIndex = core.countListYposition()
                for(var i = 0; i < minIndex; i++)
                    ctx.lineTo(core.getListXposition()[i], core.getListYposition()[i]);
                ctx.stroke()
            }
        }

        GridView {
            id: depthGridView
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -30
            anchors.left: parent.left
            anchors.right: parent.right
            height: 30
            model: core.model
            interactive: false
            delegate: Rectangle {
                id: sensorRect
                width: 30
                height: 30
                color: modelColor
//                x: modelX
                MouseArea {
                    anchors.fill: parent
                    drag.target: switchEdit.position ? parent : null
                }

                onXChanged: {
                    if(x < 0)
                        x = 0
                    if(x > depthGridView.width)
                        x = depthGridView.width - width
//                    x = modelX
//                    core.updateList()
//                    waveCanvas.requestPaint()
//                    console.log(sensorRect.x)
                }
                onYChanged: {
                    y = depthGridView.height + depthGridView.anchors.bottomMargin
//                    waveCanvas.requestPaint()
                }
            }
        }


//        PathView {
//            id: stringPath
//            anchors.fill: parent
//            model: core.model
//            delegate: Rectangle {
//                width: 30
//                height: 30
//                color: modelColor
//            }

//            path: Path {
//                startX: 0; startY: 0
//                PathLine { x: stringPath.width; y: 0 }
//            }
//        }
    }

//    ListView {
//        anchors.fill: parent
//        model: core.model
//        delegate: Rectangle {
//            width: 300
//            height: 100
//            color: modelColor
//            Text {
//                text: modelName
//                font.pixelSize: 20
//            }

//        }
//    }

}
