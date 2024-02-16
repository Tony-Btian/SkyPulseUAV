# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SkyPulseUVA_GroundStation_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SkyPulseUVA_GroundStation_autogen.dir/ParseCache.txt"
  "SkyPulseUVA_GroundStation_autogen"
  )
endif()
