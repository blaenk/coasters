#include <iostream>
#include "script/Lua.h"

int main(int argc, char *argv[]) {
  Lua lua;
  lua.OpenLibraries();
  lua.LoadFile("scripts/test.lua");

  lua.PCall();

  system("PAUSE");

  return 0;
}
