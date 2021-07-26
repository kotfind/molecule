#include "Engine/Engine.h"

#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error: Too few arguments" << std::endl;
        return 0;
    }
    Engine* engine = new Engine(argv[1]);
    engine->start();
    delete engine;
}
