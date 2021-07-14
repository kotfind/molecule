#include "Engine.h"

void Engine::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            run_ = 0;
        }
    }
}
