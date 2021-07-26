#include "Molecule.h"

#include "../Atom/Atom.h"

#include <unordered_map>

extern std::unordered_map<std::string, std::tuple<char, char, char>> atomColours;
extern std::unordered_map<std::string, double> atomRadii;

bool Molecule::canBind(const Atom& lhs, const Atom& rhs) const {
    return (len(lhs.pos_ - rhs.pos_) - (atomRadii[sfac_[lhs.type_]]
            + atomRadii[sfac_[rhs.type_]]) < 0.5);
}
