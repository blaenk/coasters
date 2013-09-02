#include <iostream>
#include "lua.hpp"

int main(int argc, char *argv[]) {
  lua_State *L = lua_open();

  luaL_openlibs(L);

  int s = luaL_loadfile(L, "scripts/test.lua");

  if (s == 0) {
    s = lua_pcall(L, 0, LUA_MULTRET, 0);
  } else {
    std::cerr << "ERRROR: " << lua_tostring(L, -1) << std::endl;
    lua_pop(L, 1);
  }

  system("PAUSE");

  lua_close(L);
  return 0;
}
