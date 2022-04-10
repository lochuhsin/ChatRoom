# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "controllers/CMakeFiles/controller_autogen.dir/AutogenUsed.txt"
  "controllers/CMakeFiles/controller_autogen.dir/ParseCache.txt"
  "controllers/controller_autogen"
  "helpers/CMakeFiles/helper_autogen.dir/AutogenUsed.txt"
  "helpers/CMakeFiles/helper_autogen.dir/ParseCache.txt"
  "helpers/helper_autogen"
  "models/CMakeFiles/model_autogen.dir/AutogenUsed.txt"
  "models/CMakeFiles/model_autogen.dir/ParseCache.txt"
  "models/model_autogen"
  "views/CMakeFiles/view_autogen.dir/AutogenUsed.txt"
  "views/CMakeFiles/view_autogen.dir/ParseCache.txt"
  "views/view_autogen"
  )
endif()
