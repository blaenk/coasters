#include "WindowsApplication.h"

#include "graphics/WindowsRenderer.h"
#include "graphics/D3D11Renderer.h"

#include "script/Lua.h"
using namespace Coasters::Graphics;
using namespace Coasters::Script;

namespace Coasters {
namespace Platform {

WindowsApplication::WindowsApplication() : hWnd_(0), renderer_(nullptr) {
  this->renderer_ = new D3D11Renderer;
  WNDCLASSEX wc;
  HINSTANCE hInstance = GetModuleHandle(NULL);

  ZeroMemory(&wc, sizeof(WNDCLASSEX));

  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wc.lpszClassName = "WindowClass";

  RegisterClassEx(&wc);

  RECT wr = {0, 0, 800, 600};
  AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

  this->hWnd_ = CreateWindowEx(NULL,
                               "WindowClass",
                               "Coasters!",
                               WS_OVERLAPPEDWINDOW,
                               300,
                               300,
                               wr.right - wr.left,
                               wr.bottom - wr.top,
                               NULL,
                               NULL,
                               hInstance,
                               NULL);

  ShowWindow(this->hWnd_, SW_SHOW);
  this->renderer_->Initialize(this->hWnd_);
}

WindowsApplication::~WindowsApplication() {}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }

  return DefWindowProc(hWnd, message, wParam, lParam);
}

void WindowsApplication::Initialize() {
}

int WindowsApplication::Run() {
  MSG msg;
  while (TRUE) {
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);

      if (msg.message == WM_QUIT) break;
    } else {
      this->renderer_->Render();
    }
  }

  this->renderer_->ShutDown();

  return 0;
}

} // Platform
} // Coasters
