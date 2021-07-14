#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"

#include <vector>

class Engine;

class Molecule {
    public:
        Molecule();
        void draw(const Engine& engine) const;

        std::vector<Atom> atoms;
};

#endif
