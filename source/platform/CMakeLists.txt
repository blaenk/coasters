set (PLATFORM_SRC ${PLATFORM_SRC} Application.h
                                  Application.cpp)

add_library (platform STATIC ${PLATFORM_SRC})
target_link_libraries (platform engine)

