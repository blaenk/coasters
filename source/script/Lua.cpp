#include "Lua.h"

#include <iostream>

Lua::Lua() : state(luaL_newstate(), lua_close) {
}

Lua::~Lua() {
}

void Lua::OpenLibraries() {
  luaL_openlibs(state.get());
}

void Lua::LoadFile(std::string filename) {
  if (luaL_loadfile(state.get(), filename.c_str()) != 0) {
    std::cerr << "ERROR: " << lua_tostring(state.get(), -1) << std::endl;
  }
}

void Lua::PCall() {
  if (lua_pcall(state.get(), 0, LUA_MULTRET, 0) != 0) {
    std::cerr << "ERROR: " << lua_tostring(state.get(), -1) << std::endl;
  }
}
