#include "Data.hpp"
#include "Figures.hpp"
#include "Version.hpp"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#ifndef CADMIUM_VERSION_MAJOR
#error("No version info")
#endif

const size_t width = 1024;
const size_t height = 768;
const float fov = M_PI / 3.;

bool storePPM(std::string filename, FrameBuffer<Vector<float>> fb) {
  std::ofstream fout("./" + filename + ".ppm", std::ios::binary);
  fout << "P6\n" << fb.getWidth() << " " << fb.getHeight() << "\n255\n";

  for (const auto &Vector : fb) {
    fout << (uint8_t)(255 * Vector.red) << (uint8_t)(255 * Vector.green)
         << (uint8_t)(255 * Vector.blue);
  }

  fout << std::flush;

  fout.close();
}

int32_t main(int32_t argc, char **argv) {
  std::cout << argv[0] << " " << CADMIUM_VERSION_MAJOR << "."
            << CADMIUM_VERSION_MINOR << " version" << std::endl;

  Sphere sphere(Vector<float>(0, 0, -10), 1);

  FrameBuffer<Vector<float>> data(width, height);
  for (std::size_t w = 0; w < width; w++) {
    for (std::size_t h = 0; h < height; h++) {
      float x = (2 * (w + 0.5) / (float)width - 1) * std::tan(fov / 2.) *
                width / (float)height;
      float y = (2 * (h + 0.5) / (float)height - 1) * std::tan(fov / 2.);

      Ray ray(Vector<float>(0, 0, 0), Vector<float>(x, y, -1).normalize());

      if (sphere.isIntersectGeometric(ray)) {
        data(w, h) = Vector<float>(0.4, 0.4, 0.3);
      } else {
        data(w, h) = Vector<float>(0.2, 0.7, 0.8);
      }
    }
  }

  std::string filename = "example";
  std::cout << "Save ./" << filename << ".ppm\nHeight: " << data.getHeight()
            << " Width: " << data.getWidth() << std::endl;
  storePPM(filename, data);

  return 0;
}
