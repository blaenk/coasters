#ifndef D3D11_RENDERER_H
#define D3D11_RENDERER_H

#include "WindowsRenderer.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>

namespace Coasters {
namespace Graphics {

class D3D11Renderer : public WindowsRenderer {
public:
  D3D11Renderer();
  ~D3D11Renderer();

  bool Initialize(HWND hwnd);
  void ShutDown() override;
  void Render() override;

private:
  IDXGISwapChain *swapChain_;
  ID3D11Device *device_;
  ID3D11DeviceContext *deviceContext_;
  ID3D11RenderTargetView *backBuffer_;
};

} // Graphics
} // Coasters
#endif
