import QtQuick 2.12
import QtQuick.Window 2.12

import OGLFbo 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qml Ogre1")

    Row
    {
        Repeater
        {
            model: 3

            delegate: Render {
                width: 100
                height: 100

                MouseArea
                {
                    drag.target: parent
                    anchors.fill: parent
                    drag.minimumX: 0
                    drag.minimumY: 0
                }
            }
        }
    }
}
