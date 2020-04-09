import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 290
    height: 600
    property alias case00Text: case00.text
    title: qsTr("2048")


    Rectangle {
        id: fond
        x: 0
        y: 0
        width: 290
        height: 600
        color: "#fcf3e1"
        border.width: 0
        focus: true
        Keys.onPressed: {
            switch (event.key) {
            case Qt.Key_P:
                vueObjetCpt.initial();
                break;
            case Qt.Key_Z:
                if(vueObjetCpt.move_up()==1)
                {vueObjetCpt.maj();}
                break;
            case Qt.Key_Q:
                if(vueObjetCpt.move_left()==1)
                {vueObjetCpt.maj();}
                break;
            case Qt.Key_D:
                if(vueObjetCpt.move_right()==1)
                {vueObjetCpt.maj();}
                break;
            case Qt.Key_S:
                if(vueObjetCpt.move_down()==1)
                {vueObjetCpt.maj();}
                break;
            case Qt.Key_R:
            vueObjetCpt.retour();
                break;


            }}

        Rectangle {
            id: carre1
            x: 10
            y: 40
            width: 60
            height: 60
            color: vueObjetCpt.couleurQML[0]
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 6
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
            radius: 6
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
            radius: 6
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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
            radius: 5
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

        Text {
            id: element
            x: 68
            y: 364
            width: 154
            height: 14
            text: qsTr("Press P to start the game")
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }


        Rectangle {
            id: rectangle
            x: 214
            y: 465
            width: 20
            height: 20
            color: "#edb170"
            radius: 5
            border.width: 1

            Text {
                id: element2
                x: 7
                y: 3
                width: 7
                height: 14
                text: qsTr("Z")
                font.pixelSize: 12
            }
        }



        Text {
            id: element1
            x: 10
            y: 459
            width: 154
            height: 127
            text: qsTr("During the game, use Z,Q,S  ")
            padding: 0
            lineHeight: 1.1
            fontSizeMode: Text.HorizontalFit
            renderType: Text.QtRendering
            textFormat: Text.PlainText
            elide: Text.ElideNone
            verticalAlignment: Text.AlignTop
            font.pixelSize: 12

            Text {
                id: element5
                x: 0
                y: 69
                text: qsTr("Use R to undo.")
                font.pixelSize: 12
            }
        }

        Text {
            id: element3
            x: 10
            y: 476
            width: 99
            height: 14
            text: qsTr("and D to move UP,")
            font.pixelSize: 12
        }

        Text {
            id: element4
            x: 10
            y: 491
            text: qsTr("LEFT, DOWN and RIGHT.")
            font.pixelSize: 12
        }

        Rectangle {
            id: rectangle1
            x: 214
            y: 491
            width: 20
            height: 20
            color: "#edb170"
            radius: 5
            border.width: 1
        }

        Rectangle {
            id: rectangle2
            x: 190
            y: 491
            width: 20
            height: 20
            color: "#edb170"
            radius: 5
            border.width: 1
        }

        Rectangle {
            id: rectangle3
            x: 240
            y: 491
            width: 20
            height: 20
            color: "#edb170"
            radius: 5
            border.width: 1

            Text {
                id: element8
                x: 6
                y: 3
                text: qsTr("D")
                font.pixelSize: 12
            }
        }



        Text {
            id: element6
            x: 197
            y: 494
            width: 7
            height: 14
            text: qsTr("Q")
            font.pixelSize: 12
        }

        Text {
            id: element7
            x: 221
            y: 494
            text: qsTr("S")
            font.pixelSize: 12
        }

        Rectangle {
            id: rectangle4
            x: 10
            y: 399
            width: 272
            height: 4
            color: "#d9883f"
        }
    }
}


