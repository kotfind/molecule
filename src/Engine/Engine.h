#ifndef ENGINE_H
#define ENGINE_H

#include "../vec/vec.h"
#include "../Atom/Atom.h"
#include "../Bond/Bond.h"

#include <SDL2/SDL.h>

class Engine {
    public:
        Engine();
        ~Engine();
        void input();
        void start();
        auto toScreenCoords(const vec& v) const -> std::pair<int, int>;

    private:
        SDL_Window* win_ = nullptr;
        SDL_Renderer* ren_ = nullptr;
        bool run_;
        double ZNEAR_ = 1.;
        std::pair<int, int> screen_size_;

        vec camera_pos_ = {0., 0., 5.};
        const double xspeed = 0.3;
        const double zspeed = 0.4;

    friend Atom;
    friend Bond;
};

#endif
