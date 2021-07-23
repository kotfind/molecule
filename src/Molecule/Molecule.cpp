#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename)
    : atoms_(), bonds_(), sfac_(), symms_(), cell_(Matrix::unit(3)) {
    load(filename);
    generateSymms();
    applySymms();
    applyCell();
    generateBonds();
}

Molecule::~Molecule() {
    for (Atom* const atom : atoms_) {
        delete atom;
    }
    for (Bond* const bond : bonds_) {
        delete bond;
    }
    for (Symm* const symm : symms_) {
        delete symm;
    }
}
