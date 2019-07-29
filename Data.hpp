#ifndef __DATA_HPP__
#define __DATA_HPP__
#include <cstdint>
#include <vector>

template <typename T> class FrameBuffer {
public:
  FrameBuffer(std::size_t size)
      : Vectors_(std::vector<T>(size)), width_(size), height_(1){};

  FrameBuffer(std::size_t width, std::size_t height)
      : Vectors_(std::vector<T>(width * height)), width_(width),
        height_(height){};

  std::size_t getWidth() const { return width_; }
  std::size_t getHeight() const { return height_; }

  T &operator()(std::size_t pos) { return Vectors_[pos]; }
  T &operator()(std::size_t x, std::size_t y) {
    return Vectors_[x + y * width_];
  }

  typename std::vector<T>::iterator begin() { return Vectors_.begin(); }
  typename std::vector<T>::iterator end() { return Vectors_.end(); }

private:
  FrameBuffer(){};
  std::size_t width_;
  std::size_t height_;
  std::vector<T> Vectors_;
};

#endif // __DATA_HPP__
