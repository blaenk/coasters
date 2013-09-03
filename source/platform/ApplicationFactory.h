#ifndef APPLICATION_FACTORY_H
#define APPLICATION_FACTORY_H

#include <memory>

class Application;

class ApplicationFactory {
public:
  ApplicationFactory();
  ~ApplicationFactory();

  static std::unique_ptr<Application> CreateApplication();
};

#endif
