cmake_minimum_required(VERSION 3.1)

project(Molecule)

find_library(SDL2_LIB SDL2)
find_library(SDL2_TTF_LIB SDL2_ttf)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -march=native -pipe")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g3 -fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -g0")

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_executable(main
    src/atomValues.cpp
    src/Symm/apply.cpp
    src/Symm/Symm.cpp
    src/Atom/project.cpp
    src/Atom/Atom.cpp
    src/Atom/visible.cpp
    src/Atom/getDrawingRadiuse.cpp
    src/Atom/printBounds.cpp
    src/Atom/draw.cpp
    src/Matrix/unit.cpp
    src/Matrix/Matrix.cpp
    src/Matrix/rotation.cpp
    src/Molecule/sortZ.cpp
    src/Molecule/applySymms.cpp
    src/Molecule/insert.cpp
    src/Molecule/generateSymms.cpp
    src/Molecule/applyCell.cpp
    src/Molecule/generateBonds.cpp
    src/Molecule/getAtoms.cpp
    src/Molecule/Molecule.cpp
    src/Molecule/load.cpp
    src/Molecule/draw.cpp
    src/Molecule/canBind.cpp
    src/main.cpp
    src/Bond/draw.cpp
    src/Bond/Bond.cpp
    src/Engine/start.cpp
    src/Engine/Engine.cpp
    src/Engine/input.cpp
    src/Engine/toScreenCoords.cpp
    src/vec/vec.cpp
    )

target_link_libraries(main ${SDL2_LIB} ${SDL2_TTF_LIB})
