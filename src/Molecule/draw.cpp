#include "Molecule.h"

#include "../Engine/Engine.h"

void Molecule::draw(const Engine& engine) const {
    for (const Atom& atom : atoms) {
        atom.draw(engine);
    }
}
