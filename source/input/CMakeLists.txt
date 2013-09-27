# add source files
set (INPUT_SRC
     Input.cpp)

if (WIN32)
  set (INPUT_SRC ${INPUT_SRC} Input.h)
endif (WIN32)

add_library (input STATIC ${INPUT_SRC})

