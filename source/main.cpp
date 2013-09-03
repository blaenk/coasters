#include <iostream>
#include <memory>

#include "platform/Application.h"
#include "platform/ApplicationFactory.h"

int main(int argc, char *argv[]) {
  std::unique_ptr<Application> app = ApplicationFactory::CreateApplication();

  app->Initialize();
  app->Run();

  system("PAUSE");

  return 0;
}
