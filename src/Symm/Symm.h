#ifndef SYMM_H
#define SYMM_H

#include "../Matrix/Matrix.h"
#include "../vec/vec.h"

#include <string>

class Symm {
    public:
        Symm(std::string& s);
        Symm(const Matrix& m, const vec& c);
        vec apply(const vec& v) const;

    private:
        Matrix m_;
        vec c_;

    friend struct std::hash<Symm>;
    friend std::ostream& operator<<(std::ostream& out, const Symm& symm);
    friend Symm operator*(const Symm& lhs, const Symm& rhs);
    friend bool operator==(const Symm& lhs, const Symm& rhs);
};

std::ostream& operator<<(std::ostream& out, const Symm& symm);

bool operator==(const Symm& lhs, const Symm& rhs);

Symm operator*(const Symm& lhs, const Symm& rhs);

namespace std {
    template<> struct hash<Symm> {
        std::size_t operator()(const Symm& symm) const noexcept;
    };
};

#endif
