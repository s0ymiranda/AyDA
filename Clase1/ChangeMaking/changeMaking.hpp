#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using ui = unsigned int;

struct PairHash
{
    size_t operator () (const std::pair<size_t, ui>& p) const
    {
        return std::hash<size_t>{}(p.first) ^ std::hash<ui>{}(p.second);
    }
};

using memory = std::unordered_map<std::pair<size_t, ui>, ui, PairHash>;

ui changeMaking(const std::vector<ui>& coins, ui target, size_t idx)
{
    ui value = coins[idx];
    ui take = 0;

    if (value > target)
    {
        take = std::numeric_limits<ui>::max();
    }
    else if (value == target)
    {
        take = 1;
    }
    else
    {
        take = 1 + changeMaking(coins, target - value, idx);
    }

    ui leave = 0;

    if (idx == 0)
    {
        leave = std::numeric_limits<ui>::max();
    }
    else
    {
        leave = changeMaking(coins, target, idx - 1);
    }
    std::cout<<take <<" " <<leave <<std::endl;
    return std::min(take, leave);
}

ui changeMakingMemoization(const std::vector<ui>& coins, ui target, size_t idx, memory& mem)
{
    memory::iterator found = mem.find(std::make_pair(idx, target));

    if (found != mem.end())
    {
        return found->second;
    }

    ui value = coins[idx];
    ui take = 0;

    if (value > target)
    {
        take = std::numeric_limits<ui>::max();
    }
    else if (value == target)
    {
        take = 1;
    }
    else
    {
        take = 1 + changeMakingMemoization(coins, target - value, idx, mem);
    }

    ui leave = 0;

    if (idx == 0)
    {
        leave = std::numeric_limits<ui>::max();
    }
    else
    {
        leave = changeMakingMemoization(coins, target, idx - 1, mem);
    }

    return mem.emplace(std::make_pair(idx, target), std::min(take, leave)).first->second;
}