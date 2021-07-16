#include "Engine.h"

#include "../Molecule/Molecule.h"

#include <SDL2/SDL.h>
#include <iostream>

void Engine::start() {
    const auto* const molecule = new Molecule("/home/kotfind/prog/c++/molecule/res/f18.ort");
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
        
        molecule->draw(*this);
        xbond.draw(*this);
        ybond.draw(*this);
        zbond.draw(*this);

        SDL_RenderPresent(ren_);
    }
    delete molecule;
}
