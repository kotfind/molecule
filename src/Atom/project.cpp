#include "Atom.h"

#include "../Engine/Engine.h"

#include <math.h>

auto Atom::project(const Engine& engine) const -> std::pair<int, int> {
    const auto pos = pos_ - engine.camera_pos_ - vec{0., 0., 3.};
    return engine.toScreenCoords(pos / pos.z * engine.ZNEAR_);
}
