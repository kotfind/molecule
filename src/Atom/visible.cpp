#include "Atom.h"

#include "../Engine/Engine.h"

bool Atom::visible(const Engine& engine) const {
    return ((vec)(engine.matrix_ * pos_)).z - engine.camera_pos_.z > 0;
}
