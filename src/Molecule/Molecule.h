#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"
#include "../Bond/Bond.h"

#include <map>
#include <list>
#include <string>

class Engine;

class Molecule {
    public:
        Molecule(const std::string& filename);
        ~Molecule();
        void draw(const Engine& engine) const;
        void load(const std::string& filename);
        void insert(Atom* const atom);
        void insert(Bond* const bond);

    private:
        std::map<std::string, Atom*> atoms;
        std::list<Bond*> bonds;
};

#endif
