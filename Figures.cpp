#include "Figures.hpp"

bool Sphere::isIntersectGeometric(const Ray &ray) {
  auto L = center_ - ray.getOrigin();
  auto tca = L * ray.getDirection();
  auto d2 = L * L - tca * tca;
  auto radius2 = radius_ * radius_;
  if (d2 > radius2)
    return false;
  auto thc = std::sqrt(radius2 - d2);
  auto t0 = tca - thc;
  auto t1 = tca + thc;
  if (t0 < 0)
    t0 = t1;
  if (t0 < 0)
    return false;

  return true;
}

bool Sphere::isIntersectAnalityc(const Ray &ray) {
  auto L = ray.getOrigin() - center_;
  float a = ray.getDirection() * ray.getDirection();
  float b = ray.getDirection() * 2.0f * L;
  float c = L * L - radius_ * radius_;
  float delta = b * b - 4 * a * c;
  if (delta < 0) {
    return false;
  } else {
    float t0 = 0.0f;
    float t1 = 0.0f;
    if (delta == 0) {
      t0 = t1 = (-b * 0.5f);
    } else {
      t0 = (-b + std::sqrt(delta)) * 0.5f;
      t1 = (-b - std::sqrt(delta)) * 0.5f;
    }

    return true;
  }
}
