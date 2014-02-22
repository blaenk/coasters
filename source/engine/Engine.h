#ifndef ENGINE_H
#define ENGINE_H

// includes
#include <SDL.h>
#include <string>
#include <memory>
#include <unordered_map>

// components
#include "input/Input.h"
#include "graphics/GLRenderer.h"
#include "game/Game.h"

namespace Coasters {
namespace Graphics { class Mesh; }
namespace Engine {

class InputService {
public:
  InputService(Input::Input *input) :
    input_(input) {}

  template <class T>
  void feedEvent(T&& event) {
    input_->feedEvent(std::forward<T>(event));
  }

  template <class T>
  void Bind(SDL_Keycode key, T&& func) {
    input_->Bind(key, std::forward<T>(func));
  }
private:
  Input::Input *input_;
};

class RendererService {
public:
  RendererService(Graphics::Renderer *renderer) :
    renderer_(renderer) {}

  template <class T>
  void registerMesh(T&& mesh) {
    renderer_->registerMesh(std::forward<T>(mesh));
  }

  template <class T>
  void registerView(T&& view) {
    renderer_->registerView(std::forward<T>(view));
  }

  template <class T>
  void registerProjection(T&& projection) {
    renderer_->registerProjection(std::forward<T>(projection));
  }
private:
  Graphics::Renderer *renderer_;
};

namespace Services {
  extern RendererService *rendererService;
  extern InputService *inputService;
} // services

class Engine {
public:
  Engine();

  void Initialize();
  double RunFrame(double lag);

private:
  Graphics::GLRenderer renderer_;
  Game::Game game_;
  Input::Input input_;
};

} // Engine
} // Coasters

#endif
