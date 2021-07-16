#include "Molecule.h"

#include "../Engine/Engine.h"

void Molecule::draw(const Engine& engine) const {
    for (Bond* const bond : bonds_) {
        bond->draw(engine);
    }
    for (const auto& [name, atom] : atoms_) {
        atom->draw(engine, sfac_);
    }
}
