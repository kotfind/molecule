#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename)
    : atoms_(), bonds_(), sfac_() {
    load(filename);
}

Molecule::~Molecule() {
    for (const auto& [name, atom] : atoms_) {
        delete atom;
    }
    for (Bond* const bond : bonds_) {
        delete bond;
    }
}
