#include "Molecule.h"
#include <iostream>

void Molecule::printData() const {
    std::cout << "ATOMS: " << atoms_.size() << '\n'
        << "BONDS: " << bonds_.size() << '\n'
        << "SYMMS: " << symms_.size() << '\n' << std::endl;
}
