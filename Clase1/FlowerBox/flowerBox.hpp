#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using ull = unsigned long long;

ull compute_max_height(const std::vector<ull>& flowerbox, long cell)
{
    if(cell < 0)
    {
        return 0;
    }

    ull r1 = compute_max_height(flowerbox, cell-1);
    ull r2 = flowerbox[cell] + compute_max_height(flowerbox, cell-2);
    return std::max(r1,r2);
}

ull compute_max_height_memo(const std::vector<ull>& flowerbox, long cell, std::unordered_map<long, ull>& memo)
{
    if (cell < 0)
    {
        return 0;
    }

    if (memo[cell] == 0)
    {
        ull r1 = compute_max_height_memo(flowerbox, cell - 1, memo);
        ull r2 = flowerbox[cell] + compute_max_height_memo(flowerbox, cell - 2, memo);

        memo[cell] = std::max(r1, r2);
    }

    return memo[cell];
}

ull compute_max_height_bottom_up(const std::vector<ull>& flowerbox)
{
    ull r1 = 0;
    ull r2 = 0;
    for(ull v: flowerbox)
    {
        ull r = std::max(v + r1, r2);
        r1 = r2;
        r2 = r;
    }
    return r2;
}

