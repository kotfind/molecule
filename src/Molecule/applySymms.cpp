#include "Molecule.h"

#include <iostream>

void Molecule::applySymms() {
    std::list<Atom*> new_atoms;
    for (Atom* atom : atoms_) {
        for (Symm* symm : symms_) {
            Atom* a = new Atom(*atom);
            a->pos_ = symm->apply(a->pos_);
            a->name_ += "_COPY";
            new_atoms.push_back(a);
        }
    }
    atoms_.insert(atoms_.end(), new_atoms.begin(), new_atoms.end());
}
