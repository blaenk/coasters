include_directories (${LUAJIT_INCLUDE_DIR})

# add_subdirectory (game)
add_subdirectory (script)
# add_subdirectory (graphics)
# add_subdirectory (sound)
# add_subdirectory (physics)
# add_subdirectory (network)

add_executable (coasters main.cpp)
target_link_libraries (coasters ${LUAJIT_LIBRARIES})

# for configuration dependent: $<CONFIGURATION>

add_custom_command (TARGET coasters POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${LUAJIT_DLL}
    $<TARGET_FILE_DIR:coasters>)

add_custom_command (TARGET coasters POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RESOURCES}
    $<TARGET_FILE_DIR:coasters>)

