#include <memory>
#include <SDL_main.h>
#include <SDL.h>

#include "platform/Application.h"
#include "platform/ApplicationFactory.h"

using Coasters::Platform::Application;
using Coasters::Platform::ApplicationFactory;

int main(int argc, char *argv[]) {
  return ApplicationFactory::CreateApplication()->Run();
}
