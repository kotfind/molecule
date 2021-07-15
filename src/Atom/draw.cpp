#include "Atom.h"

#include "../Engine/Engine.h"

void Atom::draw(const Engine& engine) const {
    auto v = project(engine);
    SDL_SetRenderDrawColor(engine.ren_, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 1, v.second - 1,
            v.first + 1, v.second + 1);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 1, v.second + 1,
            v.first + 1, v.second - 1);
}
