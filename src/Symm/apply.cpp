#include "Symm.h"

#include <math.h>

vec Symm::apply(const vec& v) const {
    return vec(m_ * v) + c_;
}
