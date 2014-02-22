#include "InputComponent.h"

#include "engine/Engine.h"

namespace Coasters {
namespace Game {

bool InputComponent::Initialize() {
  return true;
}

void InputComponent::Submit() {
}

void InputComponent::Bind(SDL_Keycode key, std::function<void ()> func) {
  printf("bound\n");
  Engine::Services::input->Bind(key, func);
}

void InputComponent::PostInitialize() {}
void InputComponent::Update(int delta) {}

} // Game
}
