#include "Engine.h"

#include "../vec/vec.h"

#include <iostream>

using namespace std;

auto Engine::toScreenCoords(const vec& v) const -> pair<int, int> {
    const vec screen_size =
        {(double)screen_size_.first,
         (double)screen_size_.second, 0.};

    vec ans = v * min(screen_size.x, screen_size.y);
    if (perspective_) {
        ans.y *= -1;
    } else {
        ans.x *= -1;
    }
    ans += screen_size / 2;

    return {(int)ans.x, (int)ans.y};
}
