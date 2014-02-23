set (GRAPHICS_SRC
     Mesh.cpp
     GLRenderer.cpp
     GLProgram.cpp
     GLShader.cpp
     GLMesh.cpp)

if (WIN32)
  set (GRAPHICS_SRC ${GRAPHICS_SRC} Renderer.h
                                    Mesh.h
                                    GLRenderer.h
                                    GLProgram.h
                                    GLShader.h
                                    GLMesh.h)
endif ()

add_library (graphics STATIC ${GRAPHICS_SRC})
target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
