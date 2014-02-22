#include <SDL_main.h>
#include <SDL.h>

#include "platform/Application.h"
using Coasters::Platform::Application;

int main(int argc, char *argv[]) {
  Application app(argc, argv);
  return app.Run();
}
