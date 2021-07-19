#include "Molecule.h"

#include "../Engine/Engine.h"

void Molecule::sortZ(const Engine& engine) {
    std::sort(z_atoms_.begin(), z_atoms_.end(),
        [&engine](Atom* const lhs, Atom* const rhs){
            return vec(engine.matrix_ * lhs->pos_).z >
                vec(engine.matrix_ * rhs->pos_).z;
        });
}
