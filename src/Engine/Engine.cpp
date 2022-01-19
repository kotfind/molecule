#include "Engine.h"

#include "../Molecule/Molecule.h"

#include <cassert>
#include <string>

Engine::Engine(const std::string& file) {
    molecule_ = new Molecule(file);

    assert(SDL_Init(SDL_INIT_TIMER |
                    SDL_INIT_VIDEO |
                    SDL_INIT_EVENTS) == 0);

    win_ = SDL_CreateWindow("Molecule",
           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
           800, 600,
           SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    assert(win_ != nullptr);

    ren_ = SDL_CreateRenderer(win_, -1,
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC);
    assert(ren_ != nullptr);

    TTF_Init();
    font_ = TTF_OpenFont("/usr/share/fonts/TTF/MesloLGS-NF-Regular.ttf", 16);
    great_font_ = TTF_OpenFont("/usr/share/fonts/TTF/MesloLGS-NF-Regular.ttf", 25);

    SDL_SetRenderDrawBlendMode(ren_, SDL_BLENDMODE_BLEND);

    run_ = 1;
}

Engine::~Engine() {
    TTF_CloseFont(great_font_);
    TTF_CloseFont(font_);

    SDL_DestroyWindow(win_);
    SDL_DestroyRenderer(ren_);

    SDL_Quit();

    delete molecule_;
}
