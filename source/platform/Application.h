#ifndef APPLICATION_H
#define APPLICATION_H

namespace Coasters {
namespace Platform {

class Application {
public:
  Application();
  virtual ~Application();

  virtual void Initialize() = 0;
  virtual void Run() = 0;
private:
};

} // Platform
} // Coasters

#endif
