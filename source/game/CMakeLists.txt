# add source files
set (GAME_SRC
     Game.cpp
     Camera.cpp
     Entity.cpp
     EntityComponent.cpp
     MeshComponent.cpp
     Chunk.cpp
     World.cpp)

# to show header files in msvc
if (WIN32)
  set (GAME_SRC ${GAME_SRC}
       Game.h
       Camera.h
       Entity.h
       EntityComponent.h
       MeshComponent.h
       Chunk.h
       World.h)
endif (WIN32)

add_library (game STATIC ${GAME_SRC})
