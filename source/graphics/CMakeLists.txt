# add source files
set (GRAPHICS_SRC
     GLRenderer.cpp
     GLRenderer.h)

if (WIN32)
  # set (GRAPHICS_SRC ${GRAPHICS_SRC} Renderer.h)
endif ()

add_library (graphics STATIC ${GRAPHICS_SRC})

target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

# target_link_libraries (graphics ${DirectX_D3D11_LIBRARY}
#                                 ${DirectX_D3DX11_LIBRARY})
