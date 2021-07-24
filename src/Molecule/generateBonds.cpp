#include "Molecule.h"

#include <vector>
#include <iostream>

void Molecule::generateBonds() {
    for (auto i = atoms_.begin(); i != atoms_.end(); ++i) {
        for (auto j = next(i); j != atoms_.end(); ++j) {
            if (canBind(**i, **j)) {
                insert(new Bond(*i, *j));
            }
        }
    }
}
