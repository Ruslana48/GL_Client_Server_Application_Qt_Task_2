import QtQuick 2.15
import QtQuick.Controls 2.15
import com.example.server 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Server Application")

    Server {
        id: server
    }

    Column {
        spacing: 10

        TextField {
            id: ipInput
            placeholderText: qsTr("Enter IP Address")
            text: "127.0.0.1"
        }

        TextField {
            id: portInput
            placeholderText: qsTr("Enter Port")
            text: "1234"
        }

        Button {
            text: qsTr("Start Server")
            onClicked: {
                if (ipInput.text === "" || portInput.text === "") {
                    console.error("Please enter IP address and port.");
                    return;
                }
                server.startServer(ipInput.text, parseInt(portInput.text));
            }
        }

        Button {
            text: qsTr("Stop Server")
            onClicked: {
                console.log("Stop Server button clicked");
                server.stopServer();
            }
        }


        Text {
            id: clientInfo
            text: qsTr("Client Info: None")
        }


    }

    Connections {
        target: server

        function onProcessListUpdated(processList) {
            processList.text = processList;
        }

        function processClosed(result) {
            processList.text += "\nProcess closed: " + result;
        }

        function onGotNewMessage(msg) {
            clientInfo.text = qsTr("New Message: ") + msg;
        }

        function onSmbConnected() {
            clientInfo.text = qsTr("Client connected");
        }

        function onSmbDisconnected() {
            clientInfo.text = qsTr("Client disconnected");
        }
    }
}
