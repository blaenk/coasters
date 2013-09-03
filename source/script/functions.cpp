#include <iostream>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C" {
  DLLEXPORT void testfunc() {
    std::cout << "working!" << std::endl;
  }

  DLLEXPORT int get2() {
    return 2; // values pushed to stack
  }
}
