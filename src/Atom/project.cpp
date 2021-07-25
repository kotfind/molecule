#include "Atom.h"

#include "../Engine/Engine.h"

#include <math.h>

auto Atom::project(const Engine& engine) const -> std::pair<int, int> {
    vec pos = engine.matrix_ * pos_;
    pos -= engine.camera_pos_;
    if (engine.perspective_) {
        return engine.toScreenCoords(pos / pos.z * engine.ZNEAR_);
    } else {
        return engine.toScreenCoords(pos * (engine.ZNEAR_ / engine.camera_pos_.z));
    }
}
