#include "Molecule.h"

#include "../Engine/Engine.h"

void Molecule::draw(const Engine& engine) const {
    for (Atom* const atom : atoms) {
        atom->draw(engine);
    }
}
