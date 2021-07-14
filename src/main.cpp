#include <iostream>

#include "Engine/Engine.h"

int main() {
    Engine* engine = new Engine();
    engine->start();
    delete engine;
}
