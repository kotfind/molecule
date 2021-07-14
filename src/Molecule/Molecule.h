#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"

#include <vector>
#include <string>

class Engine;

class Molecule {
    public:
        Molecule(const std::string& filename);
        void draw(const Engine& engine) const;
        void load(const std::string& filename);
        void insert(const Atom& atom);

    private:
        std::vector<Atom> atoms;
};

#endif
