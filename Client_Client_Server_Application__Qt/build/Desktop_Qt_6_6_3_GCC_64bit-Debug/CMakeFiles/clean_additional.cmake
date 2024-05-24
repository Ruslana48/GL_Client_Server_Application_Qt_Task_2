# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appClient_Client_Server_Application__Qt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appClient_Client_Server_Application__Qt_autogen.dir/ParseCache.txt"
  "appClient_Client_Server_Application__Qt_autogen"
  )
endif()
