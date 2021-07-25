#ifndef BOND_H
#define BOND_H

#include "../Atom/Atom.h"

#include <list>

class Bond {
    public:
        Bond(Atom* const first, Atom* const second);
        void draw(const Engine& engine) const;

    private:
        const std::pair<Atom*, Atom*> val_;

    friend void Atom::printBounds(const std::list<Bond*>& bonds) const;
};

#endif
