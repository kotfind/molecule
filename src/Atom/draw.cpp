#include "Atom.h"

#include "../Engine/Engine.h"

void Atom::draw(const Engine& engine) const {
    auto v = engine.toScreenCoords(project(engine.ZNEAR_));
    SDL_SetRenderDrawColor(engine.ren_, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 2, v.second - 2,
            v.first + 2, v.second + 2);
}
