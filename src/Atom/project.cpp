#include "Atom.h"

vec Atom::project(const double& ZNEAR) {
    assert(pos_.z != 0);
    return pos_ / pos_.z * ZNEAR;
}
