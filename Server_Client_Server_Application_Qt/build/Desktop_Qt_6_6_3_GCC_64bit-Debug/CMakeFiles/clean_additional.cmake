# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appServer_Client_Server_Application_Qt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appServer_Client_Server_Application_Qt_autogen.dir/ParseCache.txt"
  "appServer_Client_Server_Application_Qt_autogen"
  )
endif()
