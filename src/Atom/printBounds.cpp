#include "Atom.h"

#include "../Molecule/Molecule.h"

#include <math.h>
#include <list>
#include <iostream>

void Atom::printBounds(const std::list<Bond*>& bonds) const {
    std::list<Atom*> neighbours;
    for (Bond* const bond : bonds) {
        if (bond->val_.first == this) {
            neighbours.push_back(bond->val_.second);
        }
        if (bond->val_.second == this) {
            neighbours.push_back(bond->val_.first);
        }
    }

    std::cout << name_ << '\t';
    for (auto j = prev(neighbours.end()); j != prev(neighbours.end()); j = prev(j)) {
        std::cout << (*j)->name_ << '\t';
    }
    std::cout << std::endl;
    for (auto i = neighbours.begin(); i != prev(neighbours.end()); ++i) {
        std::cout << (*i)->name_ << '\t';
        for (auto j = prev(neighbours.end()); j != i; j = prev(j)) {
            std::cout << acos(dot((*i)->pos_ - this->pos_, (*j)->pos_ - this->pos_) / len((*i)->pos_ - this->pos_) / len((*j)->pos_ - this->pos_)) << '\t';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}
