import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 60
        height: 60
        color: "#e4d9ac"

        Text {
            id: quatre
            x: 19
            y: 4
            text: qsTr("4")
            font.bold: false
            font.family: "Calisto MT"
            font.pixelSize: 45
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:60;width:60}
}
##^##*/
