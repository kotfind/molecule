#include "Engine.h"

void Engine::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            run_ = 0;
        }
    }

    const auto* key = SDL_GetKeyboardState(nullptr);

    if (key[SDL_SCANCODE_EQUALS] && key[SDL_SCANCODE_MINUS]) {
        
    } else if (key[SDL_SCANCODE_EQUALS]) {
        ZNEAR_ *= 1.1;
    } else if (key[SDL_SCANCODE_MINUS]) {
        ZNEAR_ /= 1.1;
    }
}
