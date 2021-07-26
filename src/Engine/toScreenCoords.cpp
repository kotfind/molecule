#include "Engine.h"

#include "../vec/vec.h"

auto Engine::toScreenCoords(const vec& v) const -> std::pair<int, int> {
    const vec screen_size =
        {(double)screen_size_.first,
         (double)screen_size_.second, 0.};

    vec ans = v * std::min(screen_size.x, screen_size.y);
    if (perspective_) {
        ans.y *= -1;
    } else {
        ans.x *= -1;
    }
    ans += screen_size / 2;

    return {(int)ans.x, (int)ans.y};
}
