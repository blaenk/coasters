#ifndef LUA_H
#define LUA_H

#include <memory>
#include <string>

#include "lua.hpp"

namespace Coasters {
namespace Script {

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

} // Script
} // Coasters
#endif
