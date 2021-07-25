#ifndef ENGINE_H
#define ENGINE_H

#include "../vec/vec.h"
#include "../Atom/Atom.h"
#include "../Bond/Bond.h"
#include "../Matrix/Matrix.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Molecule;

class Engine {
    public:
        Engine();
        ~Engine();
        void input();
        void start();
        auto toScreenCoords(const vec& v) const -> std::pair<int, int>;

    private:
        void inputEvent();
        void inputKeyboard();
        void inputMouse();

        SDL_Window* win_ = nullptr;
        SDL_Renderer* ren_ = nullptr;
        bool run_;
        double ZNEAR_ = 1.;
        std::pair<int, int> screen_size_;

        Molecule* molecule_;

        vec camera_pos_ = {0., 0., 5.};

        const double xspeed = 0.3;
        const double yspeed = 0.3;
        const double zspeed = 0.4;

        const double xangle = 0.05;
        const double yangle = 0.05;
        const double zangle = 0.05;

        Matrix matrix_ = Matrix::unit(3);

        Atom* selected_ = nullptr;

        TTF_Font* font_;
        bool show_atom_lables_ = 0;

    friend Atom;
    friend Bond;
    friend Molecule;
};

#endif
