#include "Engine.h"

#include "EngineComponent.h"

#include <assert.h>

namespace Coasters {
namespace Game {

Engine::Engine() {}

Engine::~Engine() {}

bool Engine::Initialize() {
  instance_ = new Engine;
  return true;
}

void Engine::AddComponent(std::string name, EngineComponent *component) {
  this->components_[name] = component;
}

Engine* Engine::Instance() {
  assert(instance_ != nullptr);

  return instance_;
}

} // Game
} // Coasters