#ifndef SDL_APPLICATION_H
#define SDL_APPLICATION_H

#include <memory>
#include <SDL.h>

#include "Application.h"
#include "engine/Event.h"
#include "engine/Engine.h"

namespace Coasters {
namespace Platform {

class SDLApplication : public Application {
public:
  SDLApplication();
  ~SDLApplication();

  int Run() override;
  void UpdateClock();

  void FSToggle();
  void BorderToggle();

  void OnEvent(const Engine::Event &event) override;

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
