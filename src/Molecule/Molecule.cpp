#include "Molecule.h"

#include <string>

Molecule::Molecule(const std::string& filename) : atoms() {
    load(filename);
}
