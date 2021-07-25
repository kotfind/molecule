#include "Molecule.h"

#include <iostream>

void Molecule::applySymms() {
    std::list<Atom*> new_atoms;
    do {
        atoms_.insert(atoms_.end(), new_atoms.begin(), new_atoms.end());
        new_atoms.clear();
        for (Atom* atom : atoms_) {
            for (Symm* symm : symms_) {
                Atom* a = new Atom(*atom);
                a->pos_ = symm->apply(a->pos_);
                for (int i = 0; i < 3; ++i) {
                    a->pos_[i] = fmod(a->pos_[i], 1.);
                }
                a->name_ += "*";

                bool canCreate = 0;
                for (Atom* at : atoms_) {
                    Atom* cell_a = new Atom(*a);
                    Atom* cell_at = new Atom(*at);
                    cell_a->pos_ = cell_ * cell_a->pos_;
                    cell_at->pos_ = cell_ * cell_at->pos_;
                    if (canBind(*cell_a, *cell_at)) {
                        delete cell_a;
                        delete cell_at;
                        canCreate = 1;
                        break;
                    }
                    delete cell_a;
                    delete cell_at;
                }
                for (Atom* at : atoms_) {
                    if (len(at->pos_ - a->pos_) < 0.01) {
                        canCreate = 0;
                        break;
                    }
                }
                for (Atom* at : new_atoms) {
                    if (len(at->pos_ - a->pos_) < 0.01) {
                        canCreate = 0;
                        break;
                    }
                }
                if (canCreate) {
                    new_atoms.push_back(a); 
                } else {
                    delete a;
                }
            }
        }
    } while(!new_atoms.empty());
}
