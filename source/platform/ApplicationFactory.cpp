#include "ApplicationFactory.h"

#include "Application.h"

#ifdef WIN32
#include "WindowsApplication.h"
#elif APPLE
#include "MacApplication.h"
#else
#include "LinuxApplication.h"
#endif

namespace Coasters {
namespace Platform {

ApplicationFactory::ApplicationFactory() {}

ApplicationFactory::~ApplicationFactory() {}

std::unique_ptr<Application> ApplicationFactory::CreateApplication() {
  std::unique_ptr<Application> app;

#ifdef WIN32
  app.reset(new WindowsApplication);
#elif APPLE
  app.reset(new MacApplication);
#elif UNIX
  app.reset(new LinuxApplication);
#endif

  return app;
}

} // Platform
} // Coasters
