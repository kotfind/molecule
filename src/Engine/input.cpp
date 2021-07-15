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

    if (key[SDL_SCANCODE_A] && key[SDL_SCANCODE_D]) {
    } else if (key[SDL_SCANCODE_A]) {
        camera_pos_ += {xspeed, 0., 0.};
    } else if (key[SDL_SCANCODE_D]) {
        camera_pos_ -= {xspeed, 0., 0.};
    }

    if (key[SDL_SCANCODE_W] && key[SDL_SCANCODE_S]) {
    } else if (key[SDL_SCANCODE_W]) {
        camera_pos_ -= {0., 0., zspeed};
    } else if (key[SDL_SCANCODE_S]) {
        camera_pos_ += {0., 0., zspeed};
    }

    if (key[SDL_SCANCODE_Q] && key[SDL_SCANCODE_E]) {
    } else if (key[SDL_SCANCODE_Q]) {
        matrix_ *= Matrix::yrotation(yangle);
    } else if (key[SDL_SCANCODE_E]) {
        matrix_ *= Matrix::yrotation(-yangle);
    }
}
