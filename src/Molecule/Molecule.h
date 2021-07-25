#ifndef MOLCEULE_H
#define MOLCEULE_H

#include "../Bond/Bond.h"
#include "../Symm/Symm.h"

#include <map>
#include <list>
#include <string>
#include <vector>

class Atom;
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

        bool canBind(const Atom& lhs, const Atom& rhs) const;

    private:
        void applyCell();
        void applySymms();
        void generateBonds();
        void generateSymms();
        void generateAtomsFromSymms();

        std::vector<Atom*> atoms_;
        std::list<Bond*> bonds_;
        std::vector<std::string> sfac_;
        std::list<Symm*> symms_;

        Matrix cell_;

    friend Engine;
};

#endif
