# static lib for script manager
set (SCRIPT_SRC
     Lua.cpp)

if (WIN32)
  set (SCRIPT_SRC ${SCRIPT_SRC}
       Lua.h)
endif (WIN32)

add_library (script STATIC ${SCRIPT_SRC})
target_link_libraries (script ${LUA_LIBRARIES})

# shared lib for bindings
add_library (bindings SHARED Bindings.cpp)
