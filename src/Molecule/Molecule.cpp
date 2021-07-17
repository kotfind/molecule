#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename)
    : atoms_(), bonds_(), sfac_() {
    load(filename);
    if (bonds_.empty()) {
        generateBonds();
    }
}

Molecule::~Molecule() {
    for (const auto& [name, atom] : atoms_) {
        delete atom;
    }
    for (Bond* const bond : bonds_) {
        delete bond;
    }
}
