include_directories (${LUA_INCLUDE_DIR})

add_subdirectory (game)
add_subdirectory (script)
# add_subdirectory (graphics)
# add_subdirectory (sound)
# add_subdirectory (physics)
# add_subdirectory (network)

add_executable (coasters main.cpp)
target_link_libraries (coasters script)

if (WIN32)
  add_custom_command (TARGET coasters POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${LUA_DLL}
      $<TARGET_FILE_DIR:coasters>)
endif (WIN32)

add_custom_command (TARGET coasters POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCES}
    $<TARGET_FILE_DIR:coasters>)

