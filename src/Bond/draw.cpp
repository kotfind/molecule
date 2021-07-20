#include "Bond.h"

#include "../Atom/Atom.h"
#include "../Engine/Engine.h"

void Bond::draw(const Engine& engine) const {
    if (!val_.first->visible(engine) ||
            !val_.second->visible(engine)) return;
    const auto a = val_.first->project(engine);
    const auto b = val_.second->project(engine);
    if ((val_.first == engine.selected_[0] &&
         val_.second == engine.selected_[1]) ||
        (val_.first == engine.selected_[1] &&
         val_.second == engine.selected_[2]) ||
        (val_.second == engine.selected_[0] &&
         val_.first == engine.selected_[1]) |
        (val_.second == engine.selected_[1] &&
         val_.first == engine.selected_[2])) {
        SDL_SetRenderDrawColor(engine.ren_, 0xff, 0x00, 0x00, 0xff);
    } else {
        SDL_SetRenderDrawColor(engine.ren_, 0xff, 0xff, 0xff, 0xff);
    }

    SDL_RenderDrawLine(engine.ren_, a.first, a.second,
            b.first, b.second);
}
