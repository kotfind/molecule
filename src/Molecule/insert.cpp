#include "Molecule.h"

void Molecule::insert(Atom* const atom) {
    atoms[atom->name_] = atom;
}

void Molecule::insert(Bond* const bond) {
    bonds.push_back(bond);
}
