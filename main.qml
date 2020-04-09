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
        focus: true
        Keys.onPressed: {
         switch (event.key) {
         case Qt.Key_P:
         vueObjetCpt.initial();
         break;
         case Qt.Key_Z:
         vueObjetCpt.move_up();
         vueObjetCpt.maj();
         break;
         case Qt.Key_Q:
         vueObjetCpt.move_left();
         vueObjetCpt.maj();
         break;
         case Qt.Key_D:
         vueObjetCpt.move_right();
         vueObjetCpt.maj();
         break;
         case Qt.Key_S:
         vueObjetCpt.move_down();
         vueObjetCpt.maj();
         break;


         }}

    Rectangle {
        id: carre1
        x: 10
        y: 40
        width: 60
        height: 60
        color: vueObjetCpt.couleurQML[0]
        border.color: "#9a9898"
        border.width: 2

        Text {
            id: case00
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[0]
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
            focus: true
        }
    }

    Rectangle {
        id: carre2
        x: 80
        y: 40
        width: 60
        height: 60
        color: vueObjetCpt.couleurQML[1]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case01
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[1]
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
        color: vueObjetCpt.couleurQML[2]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case02
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[2]
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
        color: vueObjetCpt.couleurQML[3]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case03
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[3]
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
        color: vueObjetCpt.couleurQML[4]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case10
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[4]
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
        color: vueObjetCpt.couleurQML[5]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case11
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[5]
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
        color: vueObjetCpt.couleurQML[6]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case12
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[6]
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
        color: vueObjetCpt.couleurQML[7]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case13
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[7]
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
        color: vueObjetCpt.couleurQML[8]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case20
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[8]
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
        color: vueObjetCpt.couleurQML[9]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case21
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[9]
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
        color: vueObjetCpt.couleurQML[10]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case22
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[10]
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
        color: vueObjetCpt.couleurQML[11]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case23
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[11]
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
        color: vueObjetCpt.couleurQML[12]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case30
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[12]
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
        color: vueObjetCpt.couleurQML[13]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case31
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[13]
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
        color: vueObjetCpt.couleurQML[14]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case32
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[14]
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
        color: vueObjetCpt.couleurQML[15]
        border.width: 2
        border.color: "#9a9898"

        Text {
            id: case33
            x: 8
            y: 8
            width: 44
            height: 44
            text: vueObjetCpt.grilleQML[15]
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }
    }
}


