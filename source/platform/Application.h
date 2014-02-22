#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <SDL.h>

#include "engine/Engine.h"

namespace Coasters {
namespace Platform {

class Application {
public:
  Application(int argc, char *argv[]);
  ~Application();

  int Run();
  void UpdateClock();
  void ProcessEvents();

  void FSToggle();
  void BorderToggle();

private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;

  Engine::Engine engine_;

  SDL_GLContext glCtx_;
  SDL_DisplayMode mode_;

  bool isRunning_;
  bool isFullscreen_;
  bool isBorderless_;

  double time_;
  double lag_;
};

} // Platform
} // Coasters

#endif
