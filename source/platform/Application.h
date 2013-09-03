#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
public:
  Application();
  virtual ~Application();

  virtual void Initialize() = 0;
  virtual void Run() = 0;
private:
};

#endif
