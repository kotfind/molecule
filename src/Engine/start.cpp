#include "Engine.h"

#include "../Molecule/Molecule.h"

#include <SDL2/SDL.h>
#include <iostream>

void Engine::start() {
    const auto* const m = new Molecule("/home/kotfind/prog/c++/molecule/res/c60.ort");
    while (run_) {
        input();

        SDL_SetRenderDrawColor(ren_, 0x00, 0x00, 0x00, 0x00);

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
        
        m->draw(*this);
        xbond.draw(*this);
        ybond.draw(*this);
        zbond.draw(*this);

        SDL_RenderPresent(ren_);
    }
    delete m;
}
