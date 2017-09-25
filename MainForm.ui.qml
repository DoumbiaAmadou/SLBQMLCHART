import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import Charts 1.0

Item {
    id: item1
    width: 340
    height: 240

//    property alias button1: button1
//    property alias button2: button2

    Item {

        width: 300;
        height: 200;
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Repeater{
            model: model.pieDatas
            delegate:  PieChart {
                id : piemodel
                anchors.centerIn: parent
                width: 100; height: 100
                slices:sliceData
            }
        }

        /* [
                PieSlice {
                    anchors.fill: parent
                    color: "red"
                    fromAngle: 0; angleSpan: 110
                },
                PieSlice {
                    anchors.fill: parent
                    color: "black"
                    fromAngle: 110; angleSpan: 50
                },
                PieSlice {
                    anchors.fill: parent
                    color: "blue"
                    fromAngle: 160; angleSpan: 100
                }
        ]*/

    }

}
