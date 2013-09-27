#ifndef WINDOWS_APPLICATION_H
#define WINDOWS_APPLICATION_H

#include <windows.h>

#include "Application.h"

namespace Coasters {
namespace Graphics { class WindowsRenderer; }
namespace Platform {

class WindowsApplication : public Application {
public:
  WindowsApplication();
  ~WindowsApplication();

  int Run() override;
  void OnEvent(const Event &event) override;

private:
  HWND hWnd_;
  Graphics::WindowsRenderer *renderer_;
};

} // Platform
} // Coasters

#endif
