#ifndef ENGINE_H
#define ENGINE_H

#include "../vec/vec.h"

#include <SDL2/SDL.h>

class Engine {
    public:
        Engine();
        ~Engine();
        void input();
        void start();
        auto toScreenCoords(const vec& v) -> std::pair<int, int>;

    private:
        SDL_Window* win_ = nullptr;
        SDL_Renderer* ren_ = nullptr;
        bool run_;
        const double ZNEAR_ = 1.;
        std::pair<int, int> screen_size_;
};

#endif
