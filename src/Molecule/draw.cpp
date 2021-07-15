#include "Molecule.h"

#include "../Engine/Engine.h"

void Molecule::draw(const Engine& engine) const {
    for (Bond* const bond : bonds) {
        bond->draw(engine);
    }
    for (const auto& [name, atom] : atoms) {
        atom->draw(engine);
    }
}
