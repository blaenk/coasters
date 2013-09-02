#ifndef LUA_H
#define LUA_H

#include <memory>
#include <string>

#include "lua.hpp"

class Lua {
public:
    Lua();
    ~Lua();

    void OpenLibraries();
    void LoadFile(std::string filename);
    void PCall();
private:
    std::unique_ptr<lua_State, decltype(lua_close) *> state;
};

#endif
