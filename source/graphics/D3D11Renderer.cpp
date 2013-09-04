#include "Renderer.h"

#include "D3D11Renderer.h"

namespace Coasters {
namespace Graphics {

D3D11Renderer::D3D11Renderer()
  : swapChain_(nullptr), device_(nullptr), deviceContext_(nullptr),
    backBuffer_(nullptr) {}

/*
swapChain_(nullptr), device_(nullptr), deviceContext_(nullptr), renderTargetView_(nullptr),
depthStencilBuffer_(nullptr), depthStencilState_(nullptr), depthStencilView_(nullptr),
rasterState_(nullptr) {}
*/

D3D11Renderer::~D3D11Renderer() {}

bool D3D11Renderer::Initialize(HWND hwnd) {
  DXGI_SWAP_CHAIN_DESC swapChainDesc;
  ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
  swapChainDesc.BufferCount = 1;
  swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  swapChainDesc.OutputWindow = hwnd;
  swapChainDesc.SampleDesc.Count = 4;
  swapChainDesc.Windowed = TRUE;

  D3D11CreateDeviceAndSwapChain(NULL,
                                D3D_DRIVER_TYPE_HARDWARE,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                D3D11_SDK_VERSION,
                                &swapChainDesc,
                                &swapChain_,
                                &device_,
                                NULL,
                                &deviceContext_);

  ID3D11Texture2D *backBuffer;
  swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&backBuffer);

  device_->CreateRenderTargetView(backBuffer, NULL, &backBuffer_);
  backBuffer->Release();

  deviceContext_->OMSetRenderTargets(1, &backBuffer_, NULL);

  D3D11_VIEWPORT viewport;
  ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

  viewport.TopLeftX = 0;
  viewport.TopLeftY = 0;
  viewport.Width = 800;
  viewport.Height = 600;

  deviceContext_->RSSetViewports(1, &viewport);

  return true;
}

void D3D11Renderer::ShutDown() {
  swapChain_->Release();
  backBuffer_->Release();
  device_->Release();
  deviceContext_->Release();
}

void D3D11Renderer::Render() {
  deviceContext_->ClearRenderTargetView(backBuffer_, D3DXCOLOR(0.0f, 0.2f, 0.4f, 1.0f));
  swapChain_->Present(0, 0);
}

} // Graphics
} // Coasters
