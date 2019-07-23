#include "Data.hpp"
#include "Version.hpp"
#include <iostream>

#ifndef CADMIUM_VERSION_MAJOR
#error("No version info")
#endif

const size_t width = 1024;
const size_t height = 768;

int32_t main(int32_t argc, char **argv) {
  std::cout << argv[0] << " " << CADMIUM_VERSION_MAJOR << "."
            << CADMIUM_VERSION_MINOR << " version" << std::endl;

  FrameBuffer<Pixel<float>> data(width, height);
  for (std::size_t w = 0; w < width; w++) {
    for (std::size_t h = 0; h < height; h++) {
      data(w, h) = Pixel<float>(w / float(width), h / float(height), 0);
    }
  }
  std::cout << "Height: " << data.getHeight() << " Width: " << data.getWidth()
            << std::endl;
  return 0;
}
