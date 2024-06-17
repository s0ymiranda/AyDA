#include "changeMaking.hpp"

int main()
{
    std::vector<ui> coins = {1, 19, 5, 12};
    ui target = 16;

    // Crónica para el algoritmo recursivo básico
    auto start_basic = std::chrono::steady_clock::now();
    ui result_basic = changeMaking(coins, target, coins.size() - 1);
    auto end_basic = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo Básico: " << result_basic << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo Básico: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_basic - start_basic).count()
         << " nanosegundos\n";

    // Crónica para el algoritmo recursivo con memoización
    auto start_memo = std::chrono::steady_clock::now();
    memory mem{};
    ui result_memo = changeMakingMemoization(coins, target, coins.size() - 1, mem);
    auto end_memo = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo con Memoización: " << result_memo << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo con Memoización: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_memo - start_memo).count()
         << " nanosegundos\n";

    return 0;
}