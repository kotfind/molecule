#include "Molecule.h"

#include "../Engine/Engine.h"
#include <vector>
#include <algorithm>

void Molecule::draw(const Engine& engine) const {
    for (Bond* const bond : bonds_) {
        bond->draw(engine);
    }
    std::vector<Atom*> z_atoms;
    z_atoms.reserve(atoms_.size());
    for (const auto& [name, atom] : atoms_) {
        z_atoms.push_back(atom);
    }
    std::sort(z_atoms.begin(), z_atoms.end(),
        [&engine](Atom* const lhs, Atom* const rhs){
            return vec(engine.matrix_ * lhs->pos_).z >
                vec(engine.matrix_ * rhs->pos_).z;
        });
    for (Atom* const atom : z_atoms) {
        atom->draw(engine, sfac_);
    }
}
