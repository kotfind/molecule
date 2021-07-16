#ifndef ATOM_COLOURS_H
#define ATOM_COLOURS_H

#include <map>
#include <string>
#include <tuple>

std::map<std::string, std::tuple<char, char, char>> atomColours = {
    {"C", {0x00, 0x00, 0x00}},
    {"H", {0xFF, 0xFF, 0xFF}},
    {"F", {0x00, 0xFF, 0xFF}},
};

#endif
