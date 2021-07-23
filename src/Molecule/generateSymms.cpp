#include "Molecule.h"

#include <unordered_set>
#include <iostream>

struct Hash {
    std::size_t operator()(Symm* symm) const {
        return std::hash<Symm>()(*symm);
    }
};

struct Pred {
    std::size_t operator()(Symm* lhs, Symm* rhs) const {
        return *lhs == *rhs;
    }
};

void Molecule::generateSymms() {
    std::unordered_set<Symm*, Hash, Pred> new_symms;
    new_symms.insert(symms_.begin(), symms_.end());
    do {
        symms_.insert(new_symms.begin(), new_symms.end());
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
                    new_symms.insert(ans);
                }
            }
        }
    } while(!new_symms.empty());
}
