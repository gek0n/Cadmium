#include <cstdint>
#include <vector>

struct Pixel {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

class FrameBuffer {
public:
  FrameBuffer(std::size_t size)
      : data_(std::vector<Pixel>(size)), width_(size), height_(1){};

  FrameBuffer(std::size_t width, std::size_t height)
      : data_(std::vector<Pixel>(width * height)), width_(width),
        height_(height){};

  std::size_t getWidth() const { return width_; }
  std::size_t getHeight() const { return height_; }

  Pixel operator()(std::size_t pos) { return data_[pos]; }
  Pixel operator()(std::size_t x, std::size_t y) {
    return data_[x + y * width_];
  }

private:
  FrameBuffer(){};
  std::size_t width_;
  std::size_t height_;
  std::vector<Pixel> data_;
};