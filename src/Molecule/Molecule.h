#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Atom/Atom.h"
#include "../Bond/Bond.h"
#include "../Symm/Symm.h"
#include "../Matrix/Matrix.h"

#include <map>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>

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
        auto getAtoms() const -> const std::vector<Atom*>&;

    private:
        void applyCell();
        void applySymms();
        void generateBonds();
        void generateSymms();
        void generateAtomsFromSymms();

        std::vector<Atom*> atoms_;
        std::list<Bond*> bonds_;
        std::vector<std::string> sfac_;
        std::unordered_set<Symm*> symms_;

        Matrix cell_;

};

#endif
