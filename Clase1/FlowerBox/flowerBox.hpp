#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;
using ull = unsigned long long;

ull compute_max_height(const vector<ull>& flowerbox, long cell)
{
    if(cell < 0)
    {
        return 0;
    }

    ull r1 = compute_max_height(flowerbox, cell-1);
    ull r2 = flowerbox[cell] + compute_max_height(flowerbox, cell-2);
    return max(r1,r2);
}

ull compute_max_height_memo(const vector<ull>& flowerbox, long cell, unordered_map<long, ull>& memo) 
{
    
    if (cell < 0) 
    {
        return 0;
    }

    if (memo[cell] == 0)
    {
        ull r1 = compute_max_height_memo(flowerbox, cell - 1, memo);
        ull r2 = flowerbox[cell] + compute_max_height_memo(flowerbox, cell - 2, memo);

        memo[cell] = max(r1, r2);
    }
   
    return memo[cell];
}

ull compute_max_height_bottom_up(const vector<ull>& flowerbox) 
{
    ull r1 = 0;
    ull r2 = 0;   
    for(ull v: flowerbox)
    {
        ull r = max(v + r1, r2);
        r1 = r2;
        r2 = r;
    } 
    return r2;
}

