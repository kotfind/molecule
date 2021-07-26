#include "Symm.h"

#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <ostream>

void replace(std::string& s, const std::string& from, const std::string& to) {
    while (s.find(from) != std::string::npos) {
        s.replace(s.find(from), from.length(), to);
    }
}

Symm::Symm(std::string& s) : m_(3) {
    replace(s, " ", "");
    replace(s, "+", ""); 
    int row = 0;
    std::unordered_map<char, int> column = {
        {'X', 0},
        {'Y', 1},
        {'Z', 2},
    };
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == ',') {
            ++row;
        } else if (c == 'X' || c == 'Y' || c == 'Z') {
            m_[row][column[c]] = (i && s[i - 1] == '-') ? -1 : 1;
        }
    }
    replace(s, "-X", "");
    replace(s, "-Y", "");
    replace(s, "-Z", "");
    replace(s, "X", "");
    replace(s, "Y", "");
    replace(s, "Z", "");
    s.push_back(',');
    std::string buffer;
    row = 0;
    for (char c : s) {
        if (c == ',') {
            if (!buffer.empty()) {
                c_[row] = fmod(std::stod(buffer) + 1., 1.);
                buffer = "";
            }
            ++row;
        } else {
            buffer += c;
        }
    }
}

Symm::Symm(const Matrix& m, const vec& c) : m_(m), c_(c) {
    for (int i = 0; i < 3; ++i) {
        c_[i] = fmod(c_[i] + 1., 1.);
    }
}

std::ostream& operator<<(std::ostream& out, const Symm& symm) {
    out << symm.m_ << '\n' << symm.c_ << std::endl;
    return out;
}

bool operator==(const Symm& lhs, const Symm& rhs) {
    return (lhs.m_ == rhs.m_) && (lhs.c_ == rhs.c_);
}

Symm operator*(const Symm& lhs, const Symm& rhs) {
    return {lhs.m_ * rhs.m_, lhs.c_ + lhs.m_ * rhs.c_};
}
