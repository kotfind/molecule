#include "Molecule.h"

auto Molecule::getZAtoms() const -> const std::vector<Atom*>& {
    return z_atoms_;
}
