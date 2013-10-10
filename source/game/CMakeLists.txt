# add source files
set (GAME_SRC
     Game.cpp
     Entity.cpp
     EntityComponent.cpp
     PositionComponent.cpp
     MeshComponent.cpp
     InputComponent.cpp
     CameraComponent.cpp
     Chunk.cpp
     World.cpp)

# to show header files in msvc
if (WIN32)
  set (GAME_SRC ${GAME_SRC}
       Game.h
       Entity.h
       EntityComponent.h
       PositionComponent.h
       MeshComponent.h
       InputComponent.h
       CameraComponent.h
       Chunk.h
       World.h)
endif (WIN32)

add_library (game STATIC ${GAME_SRC})
target_link_libraries (game graphics)
