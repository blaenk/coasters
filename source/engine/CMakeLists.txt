# add source files
set (ENGINE_SRC
     Engine.cpp
     Event.cpp
     InputEvent.cpp
     GameEvent.cpp
     RendererEvent.cpp)

if (WIN32)
  set (ENGINE_SRC ${ENGINE_SRC} Engine.h
                                Event.h
                                InputEvent.h
                                GameEvent.h
                                RendererEvent.h)
endif (WIN32)

add_library (engine STATIC ${ENGINE_SRC})
target_link_libraries (engine game graphics input)
