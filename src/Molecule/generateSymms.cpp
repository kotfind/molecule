#include "Molecule.h"

#include <list>
#include <iostream>

void Molecule::generateSymms() {
    std::list<Symm*> new_symms;
    new_symms.insert(new_symms.end(), symms_.begin(), symms_.end());
    do {
        symms_.insert(symms_.end(), new_symms.begin(), new_symms.end());
        new_symms.clear();
        for (auto i = symms_.begin(); i != symms_.end(); ++i) {
            for (auto j = i; j != symms_.end(); ++j) {
                Symm* ans = new Symm(**i * **j);
                bool found = 0;
                for (auto k = symms_.begin(); k != symms_.end(); ++k) {
                    if (*ans == **k) {
                        found = 1;
                        break;
                    }
                }
                for (auto k = new_symms.begin(); k != new_symms.end(); ++k) {
                    if (*ans == **k) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    delete ans;
                } else {
                    new_symms.push_back(ans);
                }
            }
        }
    } while(!new_symms.empty());
}
