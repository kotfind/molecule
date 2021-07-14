#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename) : atoms() {
    load(filename);
}

Molecule::~Molecule() {
    for (Atom* const atom : atoms) {
        delete atom;
    }
}
