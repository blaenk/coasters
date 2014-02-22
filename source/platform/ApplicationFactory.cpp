#include "ApplicationFactory.h"

#include "Application.h"
#include "SDLApplication.h"

namespace Coasters {
namespace Platform {

ApplicationFactory::ApplicationFactory() {}

ApplicationFactory::~ApplicationFactory() {}

std::unique_ptr<Application> ApplicationFactory::CreateApplication() {
  std::unique_ptr<Application> app(new SDLApplication);
  return app;
}

} // Platform
} // Coasters
