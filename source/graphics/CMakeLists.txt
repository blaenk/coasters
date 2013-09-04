# include_directories (${DirectX_D3D11_INCLUDE_DIR})

# add source files
set (GRAPHICS_SRC
     Renderer.cpp)

if (WIN32)
  set (GRAPHICS_SRC ${GRAPHICS_SRC} Renderer.h
                                    WindowsRenderer.cpp
                                    WindowsRenderer.h
                                    D3D11Renderer.cpp
                                    D3D11Renderer.h)
elseif (APPLE)
  set (GRAPHICS_SRC ${GRAPHICS_SRC} OpenGLRenderer.cpp)
elseif (UNIX)
  set (GRAPHICS_SRC ${GRAPHICS_SRC} OpenGLRenderer.cpp)
endif ()

add_library (graphics STATIC ${GRAPHICS_SRC})
target_link_libraries (graphics ${DirectX_D3D11_LIBRARY}
                                ${DirectX_D3DX11_LIBRARY}
                                ${DirectX_D3DX10_LIBRARY})
