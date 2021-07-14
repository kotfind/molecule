#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"

#include <vector>
#include <string>

class Engine;

class Molecule {
    public:
        Molecule(const std::string& filename);
        ~Molecule();
        void draw(const Engine& engine) const;
        void load(const std::string& filename);
        void insert(Atom* atom);

    private:
        std::vector<Atom*> atoms;
};

#endif
