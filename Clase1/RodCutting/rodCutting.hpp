#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using ull = unsigned long long;

ull rod_cutting(const std::vector<ull>& prices_table, ull n)
{
    if(n <= 0)
    {
        return 0;
    }

    ull m = 0;

    for (ull i = 1; i <= n; ++i)
    {
        m = std::max(m, prices_table[i] + rod_cutting(prices_table, n - i));
    }

    return m;
}

ull rod_cutting_memo(const std::vector<ull>& prices_table, std::vector<ull>& mem, ull n)
{
    if (mem[n] > 0)
    {
        return mem[n];
    }

    ull m = 0;

    if (n > 0)
    {
        for (ull i = 1; i <= n; ++i)
        {
            m = std::max(m, prices_table[i] + rod_cutting_memo(prices_table, mem, n - i));
        }
    }

    mem[n] = m;
    return m;
}

