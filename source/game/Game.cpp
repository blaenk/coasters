#include "Game.h"

#include <tuple>
#include <cmath>

#include "engine/Engine.h"

namespace Coasters {
namespace Game {

Game::Game(double fps) :
  updateInterval_(1 / fps),
  engine_(nullptr) {}

void Game::Update(double lag) {
  while (lag >= this->updateInterval_) {
    this->Update();
    lag -= this->updateInterval_;
  }
}

void Game::Update() {}

double Game::UpdateInterval() {
  return this->updateInterval_;
}

void Game::OnEvent(const Engine::Event& event) {
  if (this->engine_ != nullptr &&
      event.scope() != Engine::Event::Scope::Game) {
    this->engine_->OnEvent(event);
    return;
  }

  auto gevent = static_cast<const Engine::GameEvent &>(event);

  switch (gevent.subject()) {
    case Engine::GameEvent::Subject::ActorDestroyed:
      break;
  }
}

} // Game
} // Coasters