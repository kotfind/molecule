#ifndef BOND_H
#define BOND_H

#include "../Atom/Atom.h"

class Bond {
    public:
        Bond(Atom* const first, Atom* const second);
        void draw(const Engine& engine) const;

    private:
        const std::pair<Atom*, Atom*> val_;
};

#endif
