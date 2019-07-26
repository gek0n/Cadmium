#ifndef __FIGURES_HPP__
#define __FIGURES_HPP__

#include <iostream>

template <typename T> struct Pixel {
  T red;
  T green;
  T blue;
  Pixel() {}
  Pixel(T r, T g, T b) : red(r), green(g), blue(b) {}
};

class Ray {
public:
  Ray(const Pixel<float> origin, const Pixel<float> direction)
      : origin_(origin), direction_(direction) {}

  Pixel<float> getOrigin() const { return origin_; }
  Pixel<float> getDirection() const { return direction_; }

private:
  const Pixel<float> origin_;
  const Pixel<float> direction_;
};

class Sphere {
public:
  Sphere(const Pixel<float> center, const float radius)
      : center_(center), radius_(radius) {}

  Pixel<float> getCenter() const { return center_; }
  float getRadius() const { return radius_; }

  bool isIntersect(const Ray &);

private:
  const Pixel<float> center_;
  const float radius_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Pixel<T> &p);
std::ostream &operator<<(std::ostream &os, const Sphere &s);
std::ostream &operator<<(std::ostream &os, const Ray &r);

#endif // __FIGURES_HPP__
