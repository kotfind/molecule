#ifndef ATOM_H
#define ATOM_H

#include <cassert>

#include "../vec/vec.h"

#include <string>
#include <vector>
#include <list>

class Bond;
class Molecule;
class Engine;

struct Atom {
    Atom(const std::string& name, int type, const vec& pos);

    auto project(const Engine& engine) const -> std::pair<int, int>;
    void draw(const Engine& engine, const std::vector<std::string>& sfac) const;
    bool visible(const Engine& engine) const;
    int getDrawingRadius(const Engine& engine) const;

    void printBounds(const std::list<Bond*>& bonds) const;

    std::string name_;
    int type_;
    vec pos_;
};

#endif
