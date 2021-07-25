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
        
        molecule_->sortZ(*this);
        molecule_->draw(*this);

        // Perspective indicator
        if (perspective_) {
            SDL_Surface* text_surf = TTF_RenderText_Solid(great_font_, "P", {0xFF, 0x00, 0x00, 0xFF});
            SDL_Texture* text = SDL_CreateTextureFromSurface(ren_, text_surf);
            SDL_Rect text_rect = {10, 10, text_surf->w, text_surf->h};
            SDL_FreeSurface(text_surf);
            SDL_RenderCopy(ren_, text, nullptr, &text_rect);
            SDL_DestroyTexture(text);
        }

        SDL_RenderPresent(ren_);
    }
}
