cmake_minimum_required (VERSION 2.8)
project (COASTERS)

# set (CMAKE_VERBOSE_MAKEFILE on)

# for configuration dependence
# set (CMAKE_BUILD_TYPE Debug | Release)
# target_link_libraries (target DEBUG | RELEASE ${SRC})

set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set (DEPENDENCIES ${PROJECT_SOURCE_DIR}/dependencies)
set (RESOURCES    ${PROJECT_SOURCE_DIR}/resources)

# use clang on posix platforms
if (NOT WIN32)
  set(CMAKE_C_COMPILER   "clang")
  set(CMAKE_CXX_COMPILER "clang++")
endif (NOT WIN32)

# find DirectX
if (WIN32)
  find_package (DirectX)

  if (DirectX_D3D11_FOUND)
    message (STATUS "Found Direct3D 11")
  endif (DirectX_D3D11_FOUND)

  add_definitions (-D_WIN32_WINNT=0x0601 -DWINVER=0x0601)
endif (WIN32)

# use directx
# include_directories (${DirectX_D3D11_INCLUDE_DIR})
# target_link_libraries (target ${DirectX_D3D11_LIBRARY})

# find luajit
if (WIN32)
  set (LUAJIT_LIBRARIES   ${DEPENDENCIES}/luajit/src/lua51.lib)
  set (LUAJIT_DLL         ${DEPENDENCIES}/luajit/src/lua51.dll)
  set (LUAJIT_INCLUDE_DIR ${DEPENDENCIES}/luajit/src)
  set (LUAJIT_FOUND 1)
else (WIN32)
  find_package (LuaJIT)
endif (WIN32)

if (LUAJIT_FOUND)
  message (STATUS "Found LuaJIT")
else (LUAJIT_FOUND)
  message (FATAL "LuaJit required but not found")
endif (LUAJIT_FOUND)

# dependencies
# find_package (protobuf)
# find_package (PortAudio)
# find_package (DirectX)
# find_package (LuaJIT)
# find_package (SDL)
# find_package (SWIG)
# find_package (Threads)
# find_package (ZLIB)

# set (INCLUDES  ${INCLUDES}  ${PORTAUDIO_INCLUDE_DIR})
# set (LIBRARIES ${LIBRARIES} ${PORTAUDIO_LIBRARIES})

# include_directories (${INCLUDES})
# link_directories (${PORTAUDIO_LIBRARY_DIR})

# link with a library
# target_link_libraries (target ${PORTAUDIO_LIBRARIES})

add_subdirectory (source)

