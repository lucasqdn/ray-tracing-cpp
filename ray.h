#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  public:
    // Constructors for the class
    ray() {}
    ray(const point3 &origin, const vec3 &direction)
        : orig(origin), dir(direction) {}
    // Acessors for the class
    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    // Return the position of the ray when the scalar t is applied
    point3 at(double t) const { return orig + t * dir; }

  private:
    point3 orig;
    vec3 dir;
};

#endif