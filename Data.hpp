#include <cstdint>
#include <vector>

template <typename T> struct Pixel {
  T red;
  T green;
  T blue;
  Pixel() {}
  Pixel(T r, T g, T b) : red(r), green(g), blue(b) {}
};

template <typename T> class FrameBuffer {
public:
  FrameBuffer(std::size_t size)
      : pixels_(std::vector<T>(size)), width_(size), height_(1){};

  FrameBuffer(std::size_t width, std::size_t height)
      : pixels_(std::vector<T>(width * height)), width_(width),
        height_(height){};

  std::size_t getWidth() const { return width_; }
  std::size_t getHeight() const { return height_; }

  T &operator()(std::size_t pos) { return pixels_[pos]; }
  T &operator()(std::size_t x, std::size_t y) {
    return pixels_[x + y * width_];
  }

  typename std::vector<T>::iterator begin() { return pixels_.begin(); }
  typename std::vector<T>::iterator end() { return pixels_.end(); }

private:
  FrameBuffer(){};
  std::size_t width_;
  std::size_t height_;
  std::vector<T> pixels_;
};