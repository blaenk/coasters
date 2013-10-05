#ifndef INPUT_H
#define INPUT_H

// includes
#include <memory>
#include <unordered_map>
#include <vector>
#include <functional>

namespace Coasters {
namespace Engine { class Engine; }
namespace Input {

class Input {
public:
  Input();

  void Poll();
private:
  // std::unordered_map<SDL_key,
  //                    std::vector<std::function<void >>>;
};

} // Input
} // Coasters

#endif
