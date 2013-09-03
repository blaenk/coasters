#ifndef WINDOWS_APPLICATION_H
#define WINDOWS_APPLICATION_H

class Application;

class WindowsApplication : public Application {
public:
  WindowsApplication();
  ~WindowsApplication();

  void Initialize() override;
  void Run() override;
};

#endif
