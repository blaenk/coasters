#include <memory>
#include <windows.h>

#include "platform/Application.h"
#include "platform/ApplicationFactory.h"

using Coasters::Platform::Application;
using Coasters::Platform::ApplicationFactory;

#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd) {
#else
int main(int argc, char *argv[]) {
#endif
  std::unique_ptr<Application> app = ApplicationFactory::CreateApplication();

  app->Initialize();
  app->Run();

  return 0;
}
