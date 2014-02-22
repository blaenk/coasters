#include "Application.h"

#include <boost/predef.h>

#include <string>
using std::string;

#ifdef BOOST_OS_LINUX
  #include <unistd.h>
  #include <libgen.h>
#endif

#include "script/Lua.h"

namespace Coasters {
namespace Platform {

void TieToCore() {
#if BOOST_OS_WINDOWS
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

string Path() {
#ifdef BOOST_OS_LINUX
  char linkname[4096];
  ssize_t r = readlink("/proc/self/exe", linkname, 4096);

  if (r == -1)
    exit(EXIT_FAILURE);

  char *path = new char[r + 1];
  strncpy(path, linkname, r + 1);

  return dirname(path);
#else
  return "ERROR";
#endif
}

Application::Application(int argc, char *argv[]) :
  window_(nullptr, SDL_DestroyWindow), glCtx_(0),
  isFullscreen_(false), isBorderless_(false), engine_(),
  isRunning_(true) {
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

  Script::Lua lua;
  lua.OpenLibraries();
  lua.LoadFile(Path() + "/scripts/test.lua");
  lua.PCall();
}

void Application::BorderToggle() {
  SDL_SetWindowBordered(this->window_.get(), static_cast<SDL_bool>(this->isBorderless_));
  this->isBorderless_ = !this->isBorderless_;
}

void Application::FSToggle() {
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

void Application::UpdateClock() {
  double current = static_cast<double>(SDL_GetPerformanceCounter()) / SDL_GetPerformanceFrequency();
  double delta = current - this->time_;

  if (delta > 0.25)
    delta = 0.25;

  this->time_ = current;
  this->lag_ += delta;
}

void Application::ProcessEvents() {
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

    Engine::Services::input->feedEvent(event);
  }
}

int Application::Run() {
  while (this->isRunning_) {
    this->ProcessEvents();
    this->UpdateClock();

    this->lag_ = this->engine_.RunFrame(this->lag_);

    SDL_GL_SwapWindow(this->window_.get());
  }

  return 0;
}

Application::~Application() {
  SDL_GL_DeleteContext(this->glCtx_);
  SDL_Quit();
}

} // Platform
} // Coasters
