#include "Game.h"

#include <tuple>
#include <cmath>

namespace Coasters {
namespace Game {

Game::Game(double fps) :
  updateInterval_(1 / fps) {
}

void Game::Update(double lag) {
  while (lag >= this->updateInterval_) {
    this->Update();
    lag -= this->updateInterval_;
  }
}

void Game::Update() {
}

double Game::UpdateInterval() {
  return this->updateInterval_;
}

} // Game
} // Coasters
