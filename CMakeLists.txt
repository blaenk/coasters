cmake_minimum_required (VERSION 2.8)
project (COASTERS)

# set (CMAKE_VERBOSE_MAKEFILE on)

# for configuration dependence
set (CMAKE_BUILD_TYPE Debug)
# target_link_libraries (target DEBUG | RELEASE ${SRC})

set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set (DEPENDENCIES ${PROJECT_SOURCE_DIR}/dependencies)
set (RESOURCES    ${PROJECT_SOURCE_DIR}/resources)
set (SOURCE       ${PROJECT_SOURCE_DIR}/source)

# use clang on posix platforms
if (WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
else ()
  set(CMAKE_C_COMPILER   "clang")
  set(CMAKE_CXX_COMPILER "clang++")

  # C++11 goodness
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

  # Allow executable to find shared libraries
  # in the same directory as the executable ($ORIGIN)
  # this prevents having to install libraries to system-searchable paths
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-rpath,$ORIGIN")
endif ()

if (WIN32)
  list (APPEND CMAKE_PREFIX_PATH  ${DEPENDENCIES}/glew/)
  list (APPEND CMAKE_PREFIX_PATH  ${DEPENDENCIES}/SDL/)
endif ()

find_package (OpenGL REQUIRED)

if (OPENGL_FOUND)
  message (STATUS "Found OpenGL")
endif ()

find_package (GLEW REQUIRED)

if (GLEW_FOUND)
  message (STATUS "Found GLEW")
endif ()

find_package (SDL2 REQUIRED)

if (SDL2_FOUND)
  message (STATUS "Found SDL")
endif ()

# dlls
if (WIN32)
  set (SDL_DLL  ${DEPENDENCIES}/SDL/lib/SDL2.dll)
  set (GLEW_DLL ${DEPENDENCIES}/glew/bin/Release/x64/glew32.dll)
  set (LUA_DLL  ${DEPENDENCIES}/luajit/src/lua51.dll)
endif ()

# find glm
if (WIN32)
  set (GLM_ROOT_DIR ${DEPENDENCIES}/glm/)
endif ()

find_package (GLM REQUIRED)

# find luajit
if (WIN32)
  set (LUA_LIBRARIES   ${DEPENDENCIES}/luajit/src/lua51.lib)
  set (LUA_INCLUDE_DIR ${DEPENDENCIES}/luajit/src)
  set (LUA_FOUND 1)
  message (STATUS "Found LuaJIT")
else (WIN32)
  find_package (LuaJIT)
endif (WIN32)

# dependencies
# find_package (protobuf)
# find_package (vorbis)
# find_package (SDL COMPONENT mixer) ?
# find_package (PortAudio)
# find_package (Threads)
# find_package (ZLIB)

# set (INCLUDES  ${INCLUDES}  ${PORTAUDIO_INCLUDE_DIR})
# set (LIBRARIES ${LIBRARIES} ${PORTAUDIO_LIBRARIES})

# include_directories (${INCLUDES})
# link_directories (${PORTAUDIO_LIBRARY_DIR})

# link with a library
# target_link_libraries (target ${PORTAUDIO_LIBRARIES})

add_subdirectory (source)

