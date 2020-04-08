import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 290
    height: 400
    property alias case00Text: case00.text
    title: qsTr("2048")


    Rectangle {
        id: fond
        x: 0
        y: 0
        width: 290
        height: 400
        color: "#fcf3e1"
        border.width: 0
    }

    Rectangle {
        id: carre1
        x: 10
        y: 40
        width: 60
        height: 60
        color: "#e4e4e4"
        border.color: "#9a9898"
        border.width: 2

        Text {
            id: case00
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: carre2
        x: 80
        y: 40
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case01
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre3
        x: 150
        y: 40
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case02
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre4
        x: 220
        y: 40
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case03
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre5
        x: 10
        y: 110
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case10
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre6
        x: 80
        y: 110
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case11
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre7
        x: 150
        y: 110
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case12
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre8
        x: 220
        y: 110
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case13
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre9
        x: 10
        y: 180
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case20
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre10
        x: 80
        y: 180
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case21
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre11
        x: 150
        y: 180
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case22
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre12
        x: 220
        y: 180
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case23
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre13
        x: 10
        y: 252
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case30
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre14
        x: 80
        y: 252
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case31
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre15
        x: 150
        y: 252
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case32
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: carre16
        x: 220
        y: 252
        width: 60
        height: 60
        color: "#e4e4e4"
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case33
            x: 8
            y: 8
            width: 44
            height: 44
            text: qsTr("")
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

}
