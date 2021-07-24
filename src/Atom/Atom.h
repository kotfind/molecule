#ifndef ATOM_H
#define ATOM_H

#include <cassert>

#include "../vec/vec.h"

#include <string>
#include <vector>

class Engine;
class Molecule;

struct Atom {
    Atom(const std::string& name, int type, const vec& pos);

    auto project(const Engine& engine) const -> std::pair<int, int>;
    void draw(const Engine& engine, const std::vector<std::string>& sfac) const;
    bool visible(const Engine& engine) const;
    int getDrawingRadius(const Engine& engine) const;

    std::string name_;
    int type_;
    vec pos_;
};

#endif
