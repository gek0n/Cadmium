#include <iostream>
#include "Version.hpp"

#ifndef CADMIUM_VERSION_MAJOR
#error("No version info")
#endif

int32_t main(int32_t argc, char **argv) {
  std::cout << argv[0] << " " << CADMIUM_VERSION_MAJOR << "." << CADMIUM_VERSION_MINOR << " version" << std::endl;
  return 0;
}
