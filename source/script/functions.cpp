#include <iostream>

#define DLLEXPORT __declspec(dllexport)

extern "C" {
  DLLEXPORT void testfunc() {
    std::cout << "working!" << std::endl;
  }

  DLLEXPORT int get2() {
    return 2; // values pushed to stack
  }
}
