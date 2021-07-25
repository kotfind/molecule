#include "Atom.h"

#include "../Engine/Engine.h"

#include <SDL2/SDL_ttf.h>

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

    // Circle
    const int r = getDrawingRadius(engine);
    const int outline = std::max(5, r);
    const int b = 2 * (r + outline);
    for (int dx = -b; dx < b; ++dx) {
        for (int dy = -b; dy < b; ++dy) {
            const int val = dx * dx + dy * dy - r * r;
            if (val < 0) {
                SDL_SetRenderDrawColor(engine.ren_, get<0>(c), get<1>(c), get<2>(c), (dx * dx + dy * dy + r/2) / 1. / (r * r) * 255);
                SDL_RenderDrawPoint(engine.ren_,
                    v.first + dx, v.second + dy);
            } else if (this == engine.selected_ && val < outline * outline) {
                SDL_SetRenderDrawColor(engine.ren_, 0xFF, 0x00, 0x00, 0xFF);
                SDL_RenderDrawPoint(engine.ren_,
                    v.first + dx, v.second + dy);
            }
        }
    }

    // Text
    if (engine.show_atom_lables_) {
        SDL_Surface* text_surf = TTF_RenderText_Solid(engine.font_, name_.c_str(), {0x00, 0x00, 0xFF, 0xFF});
        SDL_Texture* text = SDL_CreateTextureFromSurface(engine.ren_, text_surf);
        SDL_Rect text_rect = {v.first, v.second, text_surf->w, text_surf->h};
        SDL_FreeSurface(text_surf);
        SDL_RenderCopy(engine.ren_, text, nullptr, &text_rect);
        SDL_DestroyTexture(text);
    }
}
