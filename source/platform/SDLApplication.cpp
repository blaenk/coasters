#include "SDLApplication.h"

#include <SDL_syswm.h>

namespace Coasters {
namespace Platform {

void TieToCore() {
#if defined(WIN32) || defined(_WINDOWS)
  ULONG_PTR affinity_mask;
  ULONG_PTR process_affinity_mask;
  ULONG_PTR system_affinity_mask;

  if (!GetProcessAffinityMask(GetCurrentProcess(),
                              &process_affinity_mask,
                              &system_affinity_mask)) return;

  affinity_mask = (ULONG_PTR)1 << 0;
  if (affinity_mask & process_affinity_mask)
    SetThreadAffinityMask(GetCurrentThread(), affinity_mask);
#endif
}

SDLApplication::SDLApplication() :
  window_(nullptr, SDL_DestroyWindow), glCtx_(0),
  isFullscreen_(false), isBorderless_(false), engine_() {
  TieToCore();

  SDL_Init(SDL_INIT_VIDEO);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

  SDL_GetDesktopDisplayMode(0, &this->mode_);

  this->window_.reset(SDL_CreateWindow("Coasters!",
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
                                       800, 600,
                                       SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN));

  this->glCtx_ = SDL_GL_CreateContext(this->window_.get());
  this->engine_.Initialize();
}

void SDLApplication::BorderToggle() {
  SDL_SysWMinfo info;
  SDL_VERSION(&info.version);
  SDL_GetWindowWMInfo(this->window_.get(), &info);
#ifdef WIN32
  HWND hwnd = info.info.win.window;

  if (!this->isBorderless_) {
    SetWindowLongPtr(hwnd, GWL_STYLE,
                     WS_SYSMENU | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);
    this->isBorderless_ = !this->isBorderless_;
  } else {
    RECT rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = 800;
    rect.bottom = 600;

    SetWindowLongPtr(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    this->isBorderless_ = !this->isBorderless_;
  }
#endif
}

void SDLApplication::FSToggle() {
  if (!this->isFullscreen_) {
    SDL_SetWindowFullscreen(this->window_.get(), SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowGrab(this->window_.get(), SDL_TRUE);
    this->isFullscreen_ = !this->isFullscreen_;
  } else {
    SDL_SetWindowFullscreen(this->window_.get(), 0);
    SDL_SetWindowGrab(this->window_.get(), SDL_FALSE);
    SDL_SetWindowSize(this->window_.get(), 800, 600);
    this->isFullscreen_ = !this->isFullscreen_;
  }
}

void SDLApplication::UpdateClock() {
  double current = static_cast<double>(SDL_GetPerformanceCounter()) / SDL_GetPerformanceFrequency();
  double delta = current - this->time_;

  if (delta > 0.25)
    delta = 0.25;

  this->time_ = current;
  this->lag_ += delta;
}

void SDLApplication::ProcessEvents() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      this->isRunning_ = false;
      return;
    }

    if (event.type == SDL_KEYUP) {
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          this->isRunning_ = false;
          return;
        case SDLK_f:
          this->FSToggle();
          return;
        case SDLK_b:
          this->BorderToggle();
          return;
      }
    }

    // this->engine_.FeedInput(event);
  }
}

int SDLApplication::Run() {
  while (this->isRunning_) {
    this->ProcessEvents();
    this->UpdateClock();

    this->lag_ = this->engine_.RunFrame(this->lag_);

    SDL_GL_SwapWindow(this->window_.get());
  }

  return 0;
}

SDLApplication::~SDLApplication() {
  SDL_GL_DeleteContext(this->glCtx_);
  SDL_Quit();
}

} // Platform
} // Coasters
