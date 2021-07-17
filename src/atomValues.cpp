#include <unordered_map>
#include <string>
#include <tuple>

std::unordered_map<std::string, std::tuple<char, char, char>> atomColours = {
    {"C", {0x00, 0x00, 0x00}},
    {"H", {0xFF, 0xFF, 0xFF}},
    {"F", {0x00, 0xFF, 0xFF}},
};

std::unordered_map<std::string, double> atomRadii = {
    {"C", .77},
    {"H", .32},
    {"F", .72},
};
