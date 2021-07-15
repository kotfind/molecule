#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename)
    : atoms(), bonds() {
    load(filename);
}

Molecule::~Molecule() {
    for (const auto& [name, atom] : atoms) {
        delete atom;
    }
    for (Bond* const bond : bonds) {
        delete bond;
    }
}
