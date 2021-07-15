#include "Bond.h"

Bond::Bond(Atom* const first, Atom* const second)
    : val_(first, second) {}
