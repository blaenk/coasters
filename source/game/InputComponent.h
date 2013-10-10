#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL.h>
#include <memory>
#include <string>
#include <functional>

#include "EntityComponent.h"

namespace Coasters {
namespace Game {

class InputComponent : public EntityComponent {
public:
  InputComponent() {}

  // INTERFACE
  bool Initialize() override;
  void Submit();
  void Bind(SDL_Keycode key, std::function<void ()> func);
  void PostInitialize() override;
  void Update(int delta) override;

  std::string GetName() const override { return "Input"; }
private:
  Entity *parent_;
};

} // Game
} // Coasters

#endif
