import QtQuick 2.15
import QtQuick.Controls 2.15
import com.example 1.0

ApplicationWindow {
    visible: true
    width: 1200
    height: 1200
    title: qsTr("Client Application")

    Client {
        id: client
    }

    ListModel {
        id: processListModel
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
            text: qsTr("Connect to Server")
            onClicked: {
                if (ipInput.text === "" || portInput.text === "") {
                    console.error("Please enter IP address and port.");
                    return;
                }
                client.host = ipInput.text;
                client.port = parseInt(portInput.text);
                client.connectToServer();
            }
        }

        Button {
            text: qsTr("Disconnect from Server")
            onClicked: client.closeConnection()
        }

        Text {
            id: statusText
            text: "Status: " + client.statusText
        }

        Button {
            text: qsTr("Request Process List")
            onClicked: client.requestProcessList("request_process_list", 1)
        }

        TextField {
            id: pidInput
            placeholderText: qsTr("Enter PID to close")
        }

        Button {
            text: qsTr("Close Process")
            onClicked: {
                if (pidInput.text === "") {
                    console.error("Please enter PID to close process");
                    return;
                }
                client.closeProcess(pidInput.text);
            }
        }

        ListView {
            id: processListView
            width: 300
            height: 800
            model: processListModel
            delegate: Item {
                width: processListView.width
                height: 40

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: {
                        if (mouse.button === Qt.RightButton) {
                            contextMenu.x = mouse.x
                            contextMenu.y = mouse.y
                            contextMenu.open()
                        }
                    }

                    Menu {
                        id: contextMenu
                        MenuItem {
                            text: "SIGKILL"
                            onTriggered: client.sendSignal(model.pid, 9)
                        }
                        MenuItem {
                            text: "SIGINT"
                            onTriggered: client.sendSignal(model.pid, 2)
                        }
                        MenuItem {
                            text: "SIGCONT"
                            onTriggered: client.sendSignal(model.pid, 18)
                        }
                        MenuItem {
                            text: "SIGQUIT"
                            onTriggered: client.sendSignal(model.pid, 3)
                        }
                        MenuItem {
                            text: "SIGSEGV"
                            onTriggered: client.sendSignal(model.pid, 11)
                        }
                        MenuItem {
                            text: "SIGSTOP"
                            onTriggered: client.sendSignal(model.pid, 19)
                        }
                        MenuItem {
                            text: "SIGTERM"
                            onTriggered: client.sendSignal(model.pid, 15)

                    }
                }

                Row {
                    spacing: 10
                    Text {
                        text: "PID: " + model.pid
                    }
                    Text {
                        text: "Name: " + model.processName
                    }
                    Text {
                        text: "Args: " + model.args
                    }
                }
            }
        }

    }

    Connections {
        target: client

        function onStatusChanged() {
            statusText.text = "Status: " + client.statusText;
        }

        function onProcessListReceived(processList) {
            console.log("Received process list in QML with length: " + processList.length);
            processListModel.clear();
            for (var i = 0; i < processList.length; i++) {
                console.log("Appending process: " + JSON.stringify(processList[i]));
                processListModel.append({
                    processName: processList[i].processName,
                    pid: processList[i].pid,
                    args: processList[i].args
                });
            }
        }

        function onProcessClosed(result) {
            if (result === "success") {
                console.log("Process closed successfully");
                statusText.text = "Process closed successfully";
            } else {
                console.log("Failed to close process");
                statusText.text = "Failed to close process";
            }
        }

        function onErrorOccurred(errorString) {
            console.log("Error: " + errorString);
        }
    }
}
}
