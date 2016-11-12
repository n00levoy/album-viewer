import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: textRect
        width: parent.width - 50
        height: 100
        color: "#1565c0"
        x: parent.width / 2 - width / 2
        y: 30
        radius: 10
    }

    Text {
        id: infoText
        text: "Empty"
        anchors.centerIn: textRect
        color: "#FFFFFF"

        font {
            pointSize: 20
        }
    }

    Button {
        text: "choose folder"
        anchors.centerIn: parent
        onClicked: {
            fileDialog.visible = true
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: "file:///D:/1999 - American Football/"
        //folder: shortcuts.home
        //selectFolder: true
        onAccepted: {
            infoText.text = loader.loadFromFile(fileDialog.fileUrl)
            visible = false
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
    }
}
