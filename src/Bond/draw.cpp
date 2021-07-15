#include "Bond.h"

#include "../Atom/Atom.h"
#include "../Engine/Engine.h"

void Bond::draw(const Engine& engine) const {
    if (!val_.first->visible(engine) ||
            !val_.second->visible(engine)) return;
    const auto a = val_.first->project(engine);
    const auto b = val_.second->project(engine);
    SDL_SetRenderDrawColor(engine.ren_, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderDrawLine(engine.ren_, a.first, a.second,
            b.first, b.second);
}
