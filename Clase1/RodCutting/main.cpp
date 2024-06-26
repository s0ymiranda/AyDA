#include "rodCutting.hpp"

int main()
{
    std::vector<ull> prices_table = {0, 1, 5, 8, 9};
    //vector<ull> prices_table = {0, 1, 5, 8, 9, 10, 17};
    //vector<ull> prices_table = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //vector<ull> prices_table = {0, 1, 2, 4, 6, 9, 10, 16, 18};
    ull n = prices_table.size() - 1;

    // Crónica para el algoritmo recursivo básico
    auto start_basic = std::chrono::steady_clock::now();
    ull result_basic = rod_cutting(prices_table, n);
    auto end_basic = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo Básico: " << result_basic << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo Básico: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_basic - start_basic).count()
         << " nanosegundos\n";

    // Crónica para el algoritmo recursivo con memoización
    std::vector<ull> mem(n + 1, 0);
    auto start_memo = std::chrono::steady_clock::now();
    ull result_memo = rod_cutting_memo(prices_table, mem, n);
    auto end_memo = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo con Memoización: " << result_memo << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo con Memoización: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_memo - start_memo).count()
         << " nanosegundos\n";

    return 0;
}