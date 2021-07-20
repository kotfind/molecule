#include "Molecule.h"

#include "../Engine/Engine.h"
#include <vector>
#include <algorithm>

void Molecule::draw(const Engine& engine) const {
    for (Bond* const bond : bonds_) {
        bond->draw(engine);
    }
    for (Atom* const atom : atoms_) {
        atom->draw(engine, sfac_);
    }
}
