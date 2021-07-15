#include "Atom.h"

Atom::Atom(const std::string& name, int type, const vec& pos)
    : name_(name), type_(type), pos_(pos + vec{0., 0., 10.}) {}
