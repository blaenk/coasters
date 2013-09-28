#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include <memory>
#include <string>

#include "graphics/Mesh.h"
#include "EntityComponent.h"

namespace Coasters {
namespace Game {

class MeshComponent : public EntityComponent {
public:
  MeshComponent() : mesh_(std::make_shared<Graphics::Mesh>()) {}

  // INTERFACE
  bool Initialize() override;
  void Submit();
  void PostInitialize() override;
  void Update(int delta) override;

  std::shared_ptr<Graphics::Mesh> GetMesh() {
    return mesh_;
  }

  void SetMesh(std::shared_ptr<Graphics::Mesh> mesh) {
    mesh_ = mesh;
  }

  std::string GetName() const override;
private:
  std::shared_ptr<Graphics::Mesh> mesh_;
};

} // Game
} // Coasters

#endif
