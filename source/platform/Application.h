#ifndef APPLICATION_H
#define APPLICATION_H

namespace Coasters {
namespace Platform {

class Application {
public:
  Application();
  virtual ~Application();

  virtual int Run() = 0;
private:
};

} // Platform
} // Coasters

#endif
