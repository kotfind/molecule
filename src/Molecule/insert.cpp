#include "Molecule.h"

void Molecule::insert(Atom* const atom) {
    atoms_[atom->name_] = atom;
    z_atoms_.push_back(atom);
}

void Molecule::insert(Bond* const bond) {
    bonds_.push_back(bond);
}
