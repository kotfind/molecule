#include "Engine.h"

#include "../Molecule/Molecule.h"

#include <SDL2/SDL.h>
#include <iostream>

void Engine::start() {
    while (run_) {
        input();

        SDL_SetRenderDrawColor(ren_, 0x99, 0x99, 0x99, 0xFF);

        SDL_RenderClear(ren_);

        SDL_GetRendererOutputSize(ren_, &screen_size_.first,
                &screen_size_.second);
        
        molecule_->sortZ(*this);
        molecule_->draw(*this);

        SDL_RenderPresent(ren_);
    }
}
