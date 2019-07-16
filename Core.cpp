#include "Data.hpp"
#include "Version.hpp"
#include <clang/Frontend/CompilerInstance.h>
#include <fstream>
#include <iostream>
#include <string>

#ifndef CADMIUM_VERSION_MAJOR
#error("No version info")
#endif

const size_t width = 1024;
const size_t height = 768;

bool storePPM(std::string filename, FrameBuffer<Pixel<float>> fb) {
  std::ofstream fout("./" + filename + ".ppm", std::ios::binary);
  fout << "P6\n" << fb.getWidth() << " " << fb.getHeight() << "\n255\n";

  for (const auto &pixel : fb) {
    fout << (uint8_t)(255 * pixel.red) << (uint8_t)(255 * pixel.green)
         << (uint8_t)(255 * pixel.blue);
  }

  fout << std::flush;

  fout.close();
}

void compile() {
  auto invocation = std::make_shared<clang::CompilerInvocation>();
}

int32_t main(int32_t argc, char **argv) {
  std::cout << argv[0] << " " << CADMIUM_VERSION_MAJOR << "."
            << CADMIUM_VERSION_MINOR << " version" << std::endl;

  FrameBuffer<Pixel<float>> data(width, height);
  for (std::size_t w = 0; w < width; w++) {
    for (std::size_t h = 0; h < height; h++) {
      data(w, h) = Pixel<float>(w / float(width), h / float(height), 0);
    }
  }
  std::string filename = "example";
  std::cout << "Save ./" << filename << ".ppm\nHeight: " << data.getHeight()
            << " Width: " << data.getWidth() << std::endl;
  storePPM(filename, data);
  return 0;
}
