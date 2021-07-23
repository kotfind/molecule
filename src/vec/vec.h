#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <istream>
#include <ostream>

struct vec {
    vec();
    vec(const double& v);
    vec(const double& x, const double& y, const double& z);
    vec(const vec& v);

    vec& operator=(const vec& v);
    vec& operator+=(const vec& v);
    vec& operator-=(const vec& v);
    vec& operator*=(const double& v);
    vec& operator/=(const double& v);

    double& operator[](const size_t& i);
    const double& operator[](const size_t& i) const;

    double x, y, z;
};

bool operator==(const vec& lhs, const vec& rhs);

std::istream& operator>>(std::istream& in, vec& v);
std::ostream& operator<<(std::ostream& out, const vec& v);

vec operator+(const vec& lhs, const vec& rhs);
vec operator-(const vec& lhs, const vec& rhs);
vec operator*(const vec& lhs, const double& rhs);
vec operator*(const double& lhs, const vec& rhs);
vec operator/(const vec& lhs, const double& rhs);

double len(const vec& v);
double dot(const vec& lhs, const vec& rhs);

#endif
