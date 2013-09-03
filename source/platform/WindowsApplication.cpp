#include "Application.h"

#include "WindowsApplication.h"

#include "script/Lua.h"

WindowsApplication::WindowsApplication() {
}

WindowsApplication::~WindowsApplication() {
}

void WindowsApplication::Initialize() {
}

void WindowsApplication::Run() {
  Lua lua;
  lua.OpenLibraries();
  lua.LoadFile("scripts/test.lua");

  lua.PCall();
}

