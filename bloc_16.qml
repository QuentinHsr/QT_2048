import QtQuick 2.0

Item {
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 60
        height: 60
        color: "#f7ea2e"

        Text {
            id: seize
            x: 7
            y: 4
            text: qsTr("16")
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
