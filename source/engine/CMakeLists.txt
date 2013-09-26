# add source files
set (ENGINE_SRC
     Engine.cpp
     Event.cpp
     RendererEvent.cpp)

if (WIN32)
  set (ENGINE_SRC ${ENGINE_SRC} Engine.h
                                Event.h
                                RendererEvent.h)
endif (WIN32)

add_library (engine STATIC ${ENGINE_SRC})

