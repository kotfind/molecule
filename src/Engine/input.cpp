#include "Engine.h"

void Engine::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            run_ = 0;
        }
    }

    const auto* key = SDL_GetKeyboardState(nullptr);
    bool a, b;

    a = key[SDL_SCANCODE_EQUALS];
    b = key[SDL_SCANCODE_MINUS];
    if (a & (a ^ b)) {
        ZNEAR_ *= 1.1;
    } else if (b & (a ^ b)) {
        ZNEAR_ /= 1.1;
    }

    a = key[SDL_SCANCODE_LEFT];
    b = key[SDL_SCANCODE_RIGHT];
    if (a & (a ^ b)) {
        camera_pos_ += {xspeed, 0., 0.};
    } else if (b & (a ^ b)) {
        camera_pos_ -= {xspeed, 0., 0.};
    }

    a = key[SDL_SCANCODE_UP];
    b = key[SDL_SCANCODE_DOWN];
    if (a & (a ^ b)) {
        camera_pos_ -= {0., 0., zspeed};
    } else if (b & (a ^ b)) {
        camera_pos_ += {0., 0., zspeed};
    }

    a = key[SDL_SCANCODE_W];
    b = key[SDL_SCANCODE_S];
    if (a & (a ^ b)) {
        matrix_ *= Matrix::xrotation(xangle);
    } else if (b & (a ^ b)) {
        matrix_ *= Matrix::xrotation(-xangle);
    }

    a = key[SDL_SCANCODE_A];
    b = key[SDL_SCANCODE_D];
    if (a & (a ^ b)) {
        matrix_ *= Matrix::yrotation(yangle);
    } else if (b & (a ^ b)) {
        matrix_ *= Matrix::yrotation(-yangle);
    }

    a = key[SDL_SCANCODE_Q];
    b = key[SDL_SCANCODE_E];
    if (a & (a ^ b)) {
        matrix_ *= Matrix::zrotation(zangle);
    } else if (b & (a ^ b)) {
        matrix_ *= Matrix::zrotation(-zangle);
    }
}
