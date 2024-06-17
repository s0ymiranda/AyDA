#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>


struct PairHash
{
    size_t operator () (const std::pair<size_t, int>& p) const
    {
        return std::hash<size_t>{}(p.first) ^ std::hash<int>{}(p.second);
    }
};

unsigned int change_mem_aux(const std::vector<unsigned int>& monedas, unsigned int cambio, size_t i, std::unordered_map<std::pair<size_t,unsigned int>, unsigned int, PairHash> & memory)
{
    auto found = memory.find(std::make_pair(i, cambio));

    if (found != memory.end())
    {
        return found->second;
    }

    unsigned int valor = monedas[i];
    unsigned int choice = 0;

    if (valor > cambio)
    {
        choice = std::numeric_limits<unsigned int>::max();
    }
    else if (valor == cambio)
    {
        choice = 1;
    }
    else
    {
        choice = 1 + change_mem_aux(monedas, cambio - valor, i, memory);
    }

    unsigned int leave = 0;

    if (i == 0)
    {
        leave = std::numeric_limits<unsigned int>::max();
    }
    else
    {
        leave = change_mem_aux(monedas, cambio, i - 1, memory);
    }


    return memory.emplace(std::make_pair(i, cambio), std::min(choice, leave)).first->second;
}

unsigned int change_mem(const std::vector<unsigned int>& monedas, unsigned int cambio)
{
    std::unordered_map<std::pair<size_t,unsigned int>, unsigned int, PairHash> memory;

    return change_mem_aux(monedas, cambio, monedas.size() - 1, memory);
}

int main()
{
    std::vector<unsigned int> monedas{3, 6, 5};
    int cambio = 8;

    unsigned int respuesta = change_mem(monedas, cambio);

    std::cout << respuesta;
    std::cout << "\n";

    return 0;
}