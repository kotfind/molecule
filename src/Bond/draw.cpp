#include "Bond.h"

#include "../Atom/Atom.h"
#include "../Engine/Engine.h"

void Bond::draw(const Engine& engine) const {
    const auto a = val_.first->project(engine);
    const auto b = val_.second->project(engine);
    SDL_RenderDrawLine(engine.ren_, a.first, a.second,
            b.first, b.second);
}
