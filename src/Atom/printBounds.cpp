#include "Atom.h"

#include "../Molecule/Molecule.h"

#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>

void Atom::printBounds(const std::list<Bond*>& bonds) const {
    std::vector<Atom*> a; // neighbours
    for (Bond* const bond : bonds) {
        if (bond->val_.first == this) {
            a.push_back(bond->val_.second);
        }
        if (bond->val_.second == this) {
            a.push_back(bond->val_.first);
        }
    }

    const int n = a.size();
    std::cout << "DISTANCEs to " << name_ << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i]->name_ << '\t' << len(a[i]->pos_ - pos_) << '\n';
    }
    std::cout << '\n';
    std::cout << "ANGLEs to " << name_ << ":\n";
    std::cout << "\\\t";
    for (int j = n - 1; j >= 0; --j) {
        std::cout << a[j]->name_ << '\t';
    }
    std::cout << '\n';
    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i]->name_ << '\t';
        for (int j = n - 1; j >= 0; --j) {
            const vec u = a[i]->pos_ - this->pos_;
            const vec v = a[j]->pos_ - this->pos_;
            std::cout << acos(dot(u, v) / len(u) / len(v)) << '\t';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}
