include_directories (${SOURCE}
                     ${SDL2_INCLUDE_DIR}
                     ${LUA_INCLUDE_DIR}
                     ${GLEW_INCLUDE_DIR}
                     ${OPENGL_INCLUDE_DIR}
                     ${GLM_INCLUDE_DIR}
                     ${Boost_INCLUDE_DIRS})

add_subdirectory (input)
add_subdirectory (game)
add_subdirectory (graphics)
add_subdirectory (script)
add_subdirectory (engine)
add_subdirectory (platform)
# add_subdirectory (sound)
# add_subdirectory (physics)
# add_subdirectory (network)

if (WIN32)
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable (coasters main.cpp)
  else ()
    add_executable (coasters WIN32 main.cpp)
  endif ()
else (WIN32)
  add_executable (coasters main.cpp)
endif ()

target_link_libraries (coasters
                       platform
                       script
                       ${SDL2_LIBRARY}
                       ${Boost_LIBRARY})

if (WIN32)
  add_custom_command (TARGET coasters POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${LUA_DLL}
      $<TARGET_FILE_DIR:coasters>)

  add_custom_command (TARGET coasters POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${SDL_DLL}
      $<TARGET_FILE_DIR:coasters>)

  add_custom_command (TARGET coasters POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${GLEW_DLL}
      $<TARGET_FILE_DIR:coasters>)
endif (WIN32)

add_custom_command (TARGET coasters POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCES}
    $<TARGET_FILE_DIR:coasters>)

