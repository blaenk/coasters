# add source files
set (ENGINE_SRC
     Engine.cpp)

if (WIN32)
  set (ENGINE_SRC ${ENGINE_SRC} Engine.h)
endif (WIN32)

add_library (engine STATIC ${ENGINE_SRC})
target_link_libraries (engine game graphics input)
