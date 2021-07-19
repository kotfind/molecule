#include "vec.h"

#include <math.h>

vec::vec() : vec(0) {}
vec::vec(const double& v) : vec(v, v, v) {}
vec::vec(const double& x, const double& y, const double& z) :
    x(x), y(y), z(z) {}
vec::vec(const vec& v) : x(v.x), y(v.y), z(v.z) {}

std::istream& operator>>(std::istream& in, vec& v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

std::ostream& operator<<(std::ostream& out, vec& v) {
    out << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

vec& vec::operator=(const vec& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

vec& vec::operator+=(const vec& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec& vec::operator-=(const vec& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec& vec::operator*=(const double& v) {
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

vec& vec::operator/=(const double& v) {
    x /= v;
    y /= v;
    z /= v;
    return *this;
}

vec operator+(const vec& lhs, const vec& rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

vec operator-(const vec& lhs, const vec& rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

vec operator*(const vec& lhs, const double& rhs) {
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

vec operator*(const double& lhs, const vec& rhs) {
    return rhs * lhs;
}

vec operator/(const vec& lhs, const double& rhs) {
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

double len(const vec& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot(const vec& lhs, const vec& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
