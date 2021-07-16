#include "Atom.h"

#include "../Engine/Engine.h"
#include "../atomColours.h"

#include <vector>
#include <string>

void Atom::draw(const Engine& engine, const std::vector<std::string>& sfac) const {
    if (!visible(engine)) return;
    auto v = project(engine);
    const auto& c = atomColours[sfac[type_]];
    SDL_SetRenderDrawColor(engine.ren_, get<0>(c), get<1>(c), get<2>(c), 0xff);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 5, v.second - 5,
            v.first + 5, v.second + 5);
    SDL_RenderDrawLine(engine.ren_,
            v.first - 5, v.second + 5,
            v.first + 5, v.second - 5);
}
