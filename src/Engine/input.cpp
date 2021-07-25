#include "Engine.h"

#include "../Molecule/Molecule.h"
#include "../Atom/Atom.h"

#include <iostream>
#include <vector>
#include <math.h>

void Engine::inputEvent() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            run_ = 0;
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                for (int i = 0; i < 3; ++i) {
                    selected_ = nullptr;
                }
            } else if (e.key.keysym.sym == SDLK_l) {
                show_atom_lables_ ^= 1;
            } else if (e.key.keysym.sym == SDLK_p) {
                perspective_ ^= 1;
            }
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mx, my;
            SDL_GetMouseState(&mx, &my);
            const auto& atoms = molecule_->getAtoms();
            for (int i = atoms.size() - 1; i >= 0; --i) {
                const auto& [ax, ay] = atoms[i]->project(*this);
                const int r = atoms[i]->getDrawingRadius(*this);
                const int x = ax - mx;
                const int y = ay - my;
                if (x * 1ll * x + y * 1ll * y < r * 1ll * r) {
                    selected_ = atoms[i];
                    atoms[i]->printBounds(molecule_->bonds_);
                    break;
                }
            }
        }
    }
}

void Engine::inputKeyboard() {
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
        camera_pos_ -= {xspeed, 0., 0.};
    } else if (b & (a ^ b)) {
        camera_pos_ += {xspeed, 0., 0.};
    }

    a = key[SDL_SCANCODE_UP];
    b = key[SDL_SCANCODE_DOWN];
    if (a & (a ^ b)) {
        camera_pos_ += {0., 0., zspeed};
    } else if (b & (a ^ b)) {
        camera_pos_ -= {0., 0., zspeed};
    }

    a = key[SDL_SCANCODE_LSHIFT];
    b = key[SDL_SCANCODE_LCTRL];
    if (a & (a ^ b)) {
        camera_pos_ += {0., yspeed, 0.};
    } else if (b & (a ^ b)) {
        camera_pos_ -= {0., yspeed, 0.};
    }

    a = key[SDL_SCANCODE_W];
    b = key[SDL_SCANCODE_S];
    if (a & (a ^ b)) {
        matrix_ = Matrix::xrotation(xangle) * matrix_;
    } else if (b & (a ^ b)) {
        matrix_ = Matrix::xrotation(-xangle) * matrix_;
    }

    a = key[SDL_SCANCODE_A];
    b = key[SDL_SCANCODE_D];
    if (a & (a ^ b)) {
        matrix_ = Matrix::yrotation(yangle) * matrix_;
    } else if (b & (a ^ b)) {
        matrix_ = Matrix::yrotation(-yangle) * matrix_;
    }

    a = key[SDL_SCANCODE_Q];
    b = key[SDL_SCANCODE_E];
    if (a & (a ^ b)) {
        matrix_ = Matrix::zrotation(zangle) * matrix_;
    } else if (b & (a ^ b)) {
        matrix_ = Matrix::zrotation(-zangle) * matrix_;
    }

    if (key[SDL_SCANCODE_R]) {
        matrix_ = Matrix::unit(3);
    }
}

void Engine::inputMouse() {
}

void Engine::input() {
    inputEvent();
    inputKeyboard();
    inputMouse();
}
