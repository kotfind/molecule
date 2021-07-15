#include "Atom.h"

#include "../Engine/Engine.h"

void Atom::draw(const Engine& engine) const {
    if (!visible(engine)) return;
    auto v = project(engine);
    SDL_SetRenderDrawColor(engine.ren_, 0xff, 0x00, 0x00, 0xff);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 1, v.second - 1,
            v.first + 1, v.second + 1);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 1, v.second + 1,
            v.first + 1, v.second - 1);
}
