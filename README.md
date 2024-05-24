# GL_Client_Server_Application_Qt_Task_2

## [С/С++ GL BaseCamp] Task 2

Language/libraries: C/C++, STL, usage of additional libraries or 3rd party code is prohibited.
C++17 or above should be used.
For UI QT/QML framework version 6 should be used. The application should be written using OOP.
Network-dependent code must be in a separate module.


-------------------------------------------------------
Version 2
Client/Server application to close processes on remote HOST.
- the server gets the processes list and sends them by client request.
- the client will request to close one of the processes on the server's host.
- the server has to reply with success or failure.
- Client UI should output all processes in a list with a few parameters (process name, PID, args)
- Client UI should be able to right click the process from the list and choose a signal which has to be sent to its process.
- On Success process removed from Client’s UI.
- List of processes should be updated every 10 seconds.
--------------------------------------------------------
For running server program you need to use sudo command, because closing process need admin permissions
