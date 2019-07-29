#ifndef __FIGURES_HPP__
#define __FIGURES_HPP__

#include <cmath>
#include <iostream>

template <typename T> struct Vector {
  T red;
  T green;
  T blue;
  Vector() : Vector(0, 0, 0) {}
  Vector(T r, T g, T b) : red(r), green(g), blue(b) {}

  Vector<T> operator+(const Vector<T> &v) const {
    return Vector<T>(red + v.red, green + v.green, blue + v.blue);
  }

  Vector<T> operator-(const Vector<T> &v) const {
    return Vector<T>(red - v.red, green - v.green, blue - v.blue);
  }

  T operator*(const Vector<T> &v) const {
    return red * v.red + green * v.green + blue * v.blue;
  }

  Vector<T> operator*(const T &t) const {
    return Vector<T>(t * red, t * green, t * blue);
  }

  T length() const { return sqrt(norm); }

  Vector<T> &normalize() {
    T n = norm();
    if (norm() > 0) {
      T factor = 1 / std::sqrt(n);
      red *= factor, green *= factor, blue *= factor;
    }

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Vector<T> &p) {
    return os << "(" << p.red << ", " << p.green << ", " << p.blue << ")";
  }

private:
  T norm() const { return red * red + green * green + blue * blue; }
};

class Ray {
public:
  Ray(const Vector<float> origin, const Vector<float> direction)
      : origin_(origin), direction_(direction) {}

  Vector<float> getOrigin() const { return origin_; }
  Vector<float> getDirection() const { return direction_; }

  friend std::ostream &operator<<(std::ostream &os, const Ray &r) {
    return os << "Ray origin" << r.getOrigin() << " direction"
              << r.getDirection();
  }

private:
  const Vector<float> origin_;
  const Vector<float> direction_;
};

class Sphere {
public:
  Sphere(const Vector<float> center, const float radius)
      : center_(center), radius_(radius) {}

  Vector<float> getCenter() const { return center_; }
  float getRadius() const { return radius_; }

  bool isIntersectGeometric(const Ray &ray);
  bool isIntersectAnalityc(const Ray &ray);

  friend std::ostream &operator<<(std::ostream &os, const Sphere &s) {
    return os << "Sphere center" << s.getCenter() << " radius "
              << s.getRadius();
  }

private:
  const Vector<float> center_;
  const float radius_;
};

#endif // __FIGURES_HPP__
