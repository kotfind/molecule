#ifndef ATOM_H
#define ATOM_H

#include <cassert>

#include "../vec/vec.h"

struct Atom {
    Atom();
    Atom(const vec& pos);

    vec project(const double& ZNEAR);

    const vec pos_;
};

#endif
