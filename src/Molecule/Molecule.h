#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"
#include "../Bond/Bond.h"

#include <map>
#include <list>
#include <string>
#include <vector>

class Engine;

class Molecule {
    public:
        Molecule(const std::string& filename);
        ~Molecule();
        void draw(const Engine& engine) const;
        void load(const std::string& filename);
        void insert(Atom* const atom);
        void insert(Bond* const bond);
        void sortZ(const Engine& engine);
        auto getZAtoms() const -> const std::vector<Atom*>&;

    private:
        void generateBonds();

        std::map<std::string, Atom*> atoms_;
        std::vector<Atom*> z_atoms_;
        std::list<Bond*> bonds_;
        std::vector<std::string> sfac_;
};

#endif
