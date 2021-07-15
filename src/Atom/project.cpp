#include "Atom.h"

#include "../Engine/Engine.h"

auto Atom::project(const Engine& engine) const -> std::pair<int, int> {
    assert(pos_.z != 0);
    return engine.toScreenCoords(pos_ / pos_.z * engine.ZNEAR_);
}
