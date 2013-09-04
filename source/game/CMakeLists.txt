# add source files
set (GAME_SRC
     Engine.cpp
     EngineComponent.cpp
	 Actor.cpp
	 ActorComponent.cpp
	 Voxel.cpp)

# to show header files in msvc
if (WIN32)
  set (GAME_SRC ${GAME_SRC}
       Engine.h
       EngineComponent.h
	   Actor.h
	   ActorComponent.h
	   Voxel.h)
endif (WIN32)

add_library (game STATIC ${GAME_SRC})
