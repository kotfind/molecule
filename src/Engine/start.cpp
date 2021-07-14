#include "Engine.h"

#include "../Molecule/Molecule.h"

#include <SDL2/SDL.h>
#include <iostream>

void Engine::start() {
    auto* m = new Molecule();
    m->atoms.push_back({{0., 0., 1.}});
    m->atoms.push_back({{0., 0.1, 10.}});
    while (run_) {
        input();

        SDL_SetRenderDrawColor(ren_, 0x00, 0x00, 0x00, 0x00);

        SDL_RenderClear(ren_);

        SDL_GetRendererOutputSize(ren_, &screen_size_.first,
                &screen_size_.second);
        
        m->draw(*this);

        SDL_RenderPresent(ren_);
    }
}
