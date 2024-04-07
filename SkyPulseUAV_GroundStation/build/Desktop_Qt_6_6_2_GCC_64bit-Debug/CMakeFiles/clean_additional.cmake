# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SkyPulseUAV_GroundStation_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SkyPulseUAV_GroundStation_autogen.dir/ParseCache.txt"
  "SkyPulseUAV_GroundStation_autogen"
  )
endif()
