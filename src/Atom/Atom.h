#ifndef ATOM_H
#define ATOM_H

#include <cassert>

#include "../vec/vec.h"

class Engine;

struct Atom {
    Atom();
    Atom(const vec& pos);

    vec project(const double& ZNEAR) const;
    void draw(const Engine& engine) const;

    const vec pos_;
};

#endif
