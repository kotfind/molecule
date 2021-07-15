#ifndef ATOM_H
#define ATOM_H

#include <cassert>

#include "../vec/vec.h"
#include <string>

class Engine;

struct Atom {
    Atom(const std::string& name, int type, const vec& pos);

    auto project(const Engine& engine) const -> std::pair<int, int>;
    void draw(const Engine& engine) const;

    const std::string name_;
    const int type_;
    const vec pos_;
};

#endif
