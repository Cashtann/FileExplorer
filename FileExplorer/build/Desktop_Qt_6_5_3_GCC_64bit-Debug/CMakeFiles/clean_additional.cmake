# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appFileExplorer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appFileExplorer_autogen.dir/ParseCache.txt"
  "appFileExplorer_autogen"
  )
endif()
