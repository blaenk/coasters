#include "MeshComponent.h"

#include "engine/Engine.h"

namespace Coasters {
namespace Game {

bool MeshComponent::Initialize() {
  return true;
}

void MeshComponent::Submit() {
  Engine::Services::renderer->registerMesh(mesh_);
}

void MeshComponent::PostInitialize() {}
void MeshComponent::Update(int delta) {}

std::string MeshComponent::GetName() const { return "Mesh"; }

} // Game
}
