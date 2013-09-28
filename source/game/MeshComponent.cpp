#include "MeshComponent.h"

#include "engine/Engine.h"

namespace Coasters {
namespace Game {

bool MeshComponent::Initialize() {
  return true;
}
void MeshComponent::Submit() {
  printf("registering mesh\n");
  Engine::Services::rendererService->registerMesh(mesh_);
  printf("registered mesh\n");
}
void MeshComponent::PostInitialize() {}
void MeshComponent::Update(int delta) {}

std::string MeshComponent::GetName() const { return "Mesh"; }

} // Game
}
