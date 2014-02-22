#include <memory>
#include <SDL_main.h>
#include <SDL.h>

#include "platform/SDLApplication.h"

using Coasters::Platform::SDLApplication;

int main(int argc, char *argv[]) {
  return (new SDLApplication)->Run();
}
