#include "flowerBox.hpp"

int main()
{
    std::vector<ull> flowerbox = {2, 1, 3, 7, 2, 10, 8, 20, 1, 2, 5, 1, 90, 18, 100};
    //std::vector<ull> flowerbox = {3, 10, 3, 1, 2};
    long cell = flowerbox.size() - 1;

    // Crónica para el algoritmo recursivo básico
    auto start_basic = std::chrono::steady_clock::now();
    ull result_basic = compute_max_height(flowerbox, cell);
    auto end_basic = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo Básico: " << result_basic << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo Básico: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_basic - start_basic).count()
         << " nanosegundos" << std::endl;

    // Crónica para el algoritmo recursivo con memoización
    std::unordered_map<long, ull> memo;
    auto start_memo = std::chrono::steady_clock::now();
    ull result_memo = compute_max_height_memo(flowerbox, cell, memo);
    auto end_memo = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Recursivo con Memoización: " << result_memo << std::endl;
    std::cout << "Tiempo con Algoritmo Recursivo con Memoización: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_memo - start_memo).count()
         << " nanosegundos" << std::endl;

    // Crónica para el algoritmo bottom-up
    auto start_bottom_up = std::chrono::steady_clock::now();
    ull result_bottom_up = compute_max_height_bottom_up(flowerbox);
    auto end_bottom_up = std::chrono::steady_clock::now();
    std::cout << "Resultado con Algoritmo Bottom-Up: " << result_bottom_up << std::endl;
    std::cout << "Tiempo con Algoritmo Bottom-Up: "
         << std::chrono::duration_cast<std::chrono::nanoseconds>(end_bottom_up - start_bottom_up).count()
         << " nanosegundos" << std::endl;

    return 0;
}