find_package (SWIG)
include (UseSWIG) # ${SWIG_USE_FILE}

# STATIC
add_custom_command (
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/swig.cpp
  COMMAND ${SWIG_EXECUTABLE} -lua -c++
            -o ${CMAKE_CURRENT_SOURCE_DIR}/swig.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/swig.i
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/swig.i)

add_library (script STATIC swig.cpp)
add_dependencies (script swig)

# add_custom_target (wrapper DEPENDS swig.cpp)
include_directories (${LUAJIT_INCLUDE_DIR})
target_link_libraries (script ${LUAJIT_LIBRARIES})

# DLL/SO
# include_directories (${CMAKE_CURRENT_SOURCE_DIR} ${LUAJIT_INCLUDE_DIR})
# 
# # this creates swig.dll
# # notice it should be named functions.dll since the %module is functions in swig.i
# 
# set (CMAKE_SWIG_OUTDIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
# 
# set_source_files_properties (swig.i PROPERTIES CPLUSPLUS ON)
# swig_add_module (swig lua swig.i)
# swig_link_libraries (swig ${LUAJIT_LIBRARIES})
