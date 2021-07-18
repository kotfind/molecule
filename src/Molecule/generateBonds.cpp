#include "Molecule.h"

#include <vector>
#include <unordered_map>

extern std::unordered_map<std::string, std::tuple<char, char, char>> atomColours;
extern std::unordered_map<std::string, double> atomRadii;

void Molecule::generateBonds() {
    for (auto i = atoms_.begin(); i != atoms_.end(); ++i) {
        auto* const a = i->second;
        for (auto j = next(i); j != atoms_.end(); ++j) {
            auto* const b = j->second;
            if (len(a->pos_ - b->pos_) - (atomRadii[sfac_[a->type_]]
                    + atomRadii[sfac_[a->type_]]) < 0.4) {
                insert(new Bond(a, b));
            }
        }
    }
}
