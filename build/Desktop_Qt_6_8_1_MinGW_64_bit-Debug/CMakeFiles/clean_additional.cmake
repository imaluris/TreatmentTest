# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CanConGrafica_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CanConGrafica_autogen.dir\\ParseCache.txt"
  "CanConGrafica_autogen"
  )
endif()
