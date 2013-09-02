# static lib for script manager
set (SCRIPT_SRC
     Lua.cpp)

if (WIN32)
  set (SCRIPT_SRC ${SCRIPT_SRC}
       Lua.h)
endif (WIN32)

add_library (script STATIC ${SCRIPT_SRC})

target_link_libraries (script ${LUAJIT_LIBRARIES})

# shared lib for bindings
# TODO: should this be SHARED?
add_library (bindings SHARED functions.cpp)
