#include "Molecule.h"

auto Molecule::getAtoms() const -> const std::vector<Atom*>& {
    return atoms_;
}
