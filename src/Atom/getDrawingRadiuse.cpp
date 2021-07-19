#include "Atom.h"

#include "../Engine/Engine.h"

int Atom::getDrawingRadius(const Engine& engine) const {
    const double z = (engine.matrix_ * pos_ - engine.camera_pos_).z;
    return 20. * exp(-z / 8.);
}
