#include "Atom.h"

#include "../Engine/Engine.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <math.h>

extern std::unordered_map<std::string, std::tuple<char, char, char>> atomColours;

void Atom::draw(const Engine& engine, const std::vector<std::string>& sfac) const {
    if (!visible(engine)) return;
    auto v = project(engine);
    const auto& c = atomColours[sfac[type_]];

    const int r = getDrawingRadius(engine);
    for (int dx = -2 * r; dx < 2 * r; ++dx) {
        for (int dy = -2 * r; dy < 2 * r; ++dy) {
            if (dx * dx + dy * dy - r * r < r/2) {
                SDL_SetRenderDrawColor(engine.ren_, get<0>(c), get<1>(c), get<2>(c), (dx * dx + dy * dy + r/2) / 1. / (r * r) * 255);
                SDL_RenderDrawPoint(engine.ren_,
                    v.first + dx, v.second + dy);
            }
        }
    }
}
