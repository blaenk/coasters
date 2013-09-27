# how is this handled? add the specific platform
# on a per-platform basis?

# another option is to define platform-agnostic headers with
# platform-specific implementation (cpp) files, build system
# chooses appropriate one on a per-system basis
# TODO: But then how is instance data handled?
# http://gamedev.stackexchange.com/questions/195/any-tips-for-creating-cross-platform-games/212#212

# add source files
set (PLATFORM_SRC
     Application.cpp
     ApplicationFactory.cpp)

# also CMAKE_SYSTEM_NAME is:
#   Linux, Windows, Darwin

if (WIN32)
  set (PLATFORM_SRC ${PLATFORM_SRC} Application.h
                                    ApplicationFactory.h
                                    SDLApplication.h
                                    SDLApplication.cpp)
elseif (APPLE)
  set (PLATFORM_SRC ${PLATFORM_SRC} MacApplication.cpp)
elseif (UNIX)
  set (PLATFORM_SRC ${PLATFORM_SRC} LinuxApplication.cpp)
endif ()

add_library (platform STATIC ${PLATFORM_SRC})
target_link_libraries (platform engine)

