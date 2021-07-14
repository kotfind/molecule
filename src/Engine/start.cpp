#include "Engine.h"

#include "../Atom/Atom.h"

#include <SDL2/SDL.h>
#include <iostream>

void Engine::start() {
    Atom a({0., 0., 1.});
    while (run_) {
        input();

        SDL_SetRenderDrawColor(ren_, 0x00, 0x00, 0x00, 0x00);

        SDL_RenderClear(ren_);

        SDL_GetRendererOutputSize(ren_, &screen_size_.first,
                &screen_size_.second);
        
        auto v = toScreenCoords(a.project(ZNEAR_));
        SDL_SetRenderDrawColor(ren_, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderDrawLine(ren_, v.first - 2, v.second - 2,
                                 v.first + 2, v.second + 2);

        SDL_RenderPresent(ren_);
    }
}
