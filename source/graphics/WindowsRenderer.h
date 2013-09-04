#ifndef WINDOWS_RENDERER_H
#define WINDOWS_RENDERER_H

#include <windows.h>
#include "Renderer.h"

namespace Coasters {
namespace Graphics {

class WindowsRenderer : public Renderer {
public:
  WindowsRenderer();
  ~WindowsRenderer();

  virtual bool Initialize(HWND hwnd) = 0;
};

} // Graphics
} // Coasters

#endif