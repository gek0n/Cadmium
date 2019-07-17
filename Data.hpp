#include <vector>

struct Pixel {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

class FrameBuffer {
public:
  FrameBuffer(size_t size)
      : data_(std::vector<Pixel>(size)), width_(size), height_(1){};

  FrameBuffer(size_t width, size_t height)
      : data_(std::vector<Pixel>(width * height)), width_(width),
        height_(height){};

  size_t getWidth() const { return width_; }
  size_t getHeight() const { return height_; }

  Pixel operator()(size_t pos) { return data_[pos]; }
  Pixel operator()(size_t x, size_t y) { return data_[x + y * width_]; }

private:
  FrameBuffer(){};
  size_t width_;
  size_t height_;
  std::vector<Pixel> data_;
};