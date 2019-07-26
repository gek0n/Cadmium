#include "Figures.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const Pixel<T> &p) {
  return os << "(" << p.red << ", " << p.green << ", " << p.blue << ")";
}

std::ostream &operator<<(std::ostream &os, const Sphere &s) {
  return os << "Sphere center" << s.getCenter() << " radius " << s.getRadius();
}

std::ostream &operator<<(std::ostream &os, const Ray &r) {
  return os << "Ray origin" << r.getOrigin() << " direction"
            << r.getDirection();
}

bool Sphere::isIntersect(const Ray &ray) { return false; }