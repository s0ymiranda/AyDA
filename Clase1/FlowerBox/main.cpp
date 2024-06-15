#include "flowerBox.hpp"
using namespace std;
using namespace std::chrono;
int main()
{
    //vector<ull> flowerbox = {2, 1, 3, 7, 2, 10, 8, 20, 1, 2, 5, 1, 90, 18, 100};
    vector<ull> flowerbox = {3, 10, 3, 1, 2};
    long cell = flowerbox.size() - 1;

    // Crónica para el algoritmo recursivo básico
    auto start_basic = chrono::steady_clock::now();
    ull result_basic = compute_max_height(flowerbox, cell);
    auto end_basic = chrono::steady_clock::now();
    cout << "Resultado con Algoritmo Recursivo Básico: " << result_basic << endl;
    cout << "Tiempo con Algoritmo Recursivo Básico: "
         << chrono::duration_cast<chrono::nanoseconds>(end_basic - start_basic).count()
         << " nanosegundos\n";

    // Crónica para el algoritmo recursivo con memoización
    unordered_map<long, ull> memo;
    auto start_memo = chrono::steady_clock::now();
    ull result_memo = compute_max_height_memo(flowerbox, cell, memo);
    auto end_memo = chrono::steady_clock::now();
    cout << "Resultado con Algoritmo Recursivo con Memoización: " << result_memo << endl;
    cout << "Tiempo con Algoritmo Recursivo con Memoización: "
         << chrono::duration_cast<chrono::nanoseconds>(end_memo - start_memo).count()
         << " nanosegundos\n";

    // Crónica para el algoritmo bottom-up
    auto start_bottom_up = chrono::steady_clock::now();
    ull result_bottom_up = compute_max_height_bottom_up(flowerbox);
    auto end_bottom_up = chrono::steady_clock::now();
    cout << "Resultado con Algoritmo Bottom-Up: " << result_bottom_up << endl;
    cout << "Tiempo con Algoritmo Bottom-Up: "
         << chrono::duration_cast<chrono::nanoseconds>(end_bottom_up - start_bottom_up).count()
         << " nanosegundos\n";

    return 0;
}