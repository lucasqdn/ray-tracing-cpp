#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
  public:
    double e[3];
    // Constructors for the class
    vec3() : e{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // Function for return of each value of the vector
    // Acessors for the class
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Return a new vector with the negative values of the original vector
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // Allow accessing of values of the vector using index
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    // Overloaded operators for vector addition
    vec3 &operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // Overloaded operators for vector multiplication with scalar
    vec3 &operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // Overloaded operators for vector division with scalar
    vec3 &operator/=(double t) { return *this *= 1 / t; }

    // Function to return the length of the vector and the squared length
    double length() const { return sqrt(length_squared()); }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// Aliases for vec3 class
using point3 = vec3;

// Allows printing a vec3 with <<
inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector operations component wise
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Component wise multiplication with scalar
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}
// Alternative order of multiplication
inline vec3 operator*(const vec3 &v, double t) { return t * v; }
// Component wise division with scalar
inline vec3 operator/(const vec3 &v, double t) { return (1 / t) * v; }

// Dot product of two vectors
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

// Cross product of two vectors
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Unit vector of a vector
inline vec3 unit_vector(const vec3 &v) { return v / v.length(); }

#endif