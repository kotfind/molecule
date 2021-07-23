#include "Molecule.h"

void Molecule::applyCell() {
    for (Atom* const atom : atoms_) {
        atom->pos_ = cell_ * atom->pos_;
    }
}
