# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Proyecto1_ED_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Proyecto1_ED_autogen.dir\\ParseCache.txt"
  "Proyecto1_ED_autogen"
  )
endif()
