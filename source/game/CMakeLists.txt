# add source files
set (GAME_SRC
  game.cpp
  entity.cpp)

# to show header files in msvc
if (WIN32)
  set (GAME_SRC ${GAME_SRC}
    game.h
    entity.h)
endif (WIN32)

# create a separate 'group' for the game
source_group (game FILES ${GAME_SRC})

# create library
add_library (game STATIC ${GAME_SRC})
