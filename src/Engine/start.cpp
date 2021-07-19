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

        Atom zero ("ZERO", -1, {0., 0., 0.});
        Atom xaxis("XAXI", -1, {1., 0., 0.});
        Atom yaxis("YAXI", -1, {0., 1., 0.});
        Atom zaxis("ZAXI", -1, {0., 0., 1.});
        Bond xbond(&zero, &xaxis);
        Bond ybond(&zero, &yaxis);
        Bond zbond(&zero, &zaxis);
        
        molecule_->sortZ(*this);
        molecule_->draw(*this);
        xbond.draw(*this);
        ybond.draw(*this);
        zbond.draw(*this);

        SDL_RenderPresent(ren_);
    }
}
