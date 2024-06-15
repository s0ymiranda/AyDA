#include "rodCutting.hpp"

int main()
{
    //vector<ull> prices_table = {0, 1, 5, 8, 9};
    //vector<ull> prices_table = {0, 1, 5, 8, 9, 10, 17};
    //vector<ull> prices_table = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<ull> prices_table = {0, 1 ,2 , 4, 6, 9, 10, 16, 18};
    ull n = prices_table.size() - 1;

    // Crónica para el algoritmo recursivo básico
    auto start_basic = chrono::steady_clock::now();
    ull result_basic = rod_cutting(prices_table, n);
    auto end_basic = chrono::steady_clock::now();
    cout << "Resultado con Algoritmo Recursivo Básico: " << result_basic << endl;
    cout << "Tiempo con Algoritmo Recursivo Básico: "
         << chrono::duration_cast<chrono::nanoseconds>(end_basic - start_basic).count()
         << " nanosegundos\n";

    // Crónica para el algoritmo recursivo con memoización
    vector<ull> mem(n + 1, 0);
    auto start_memo = chrono::steady_clock::now();
    ull result_memo = rod_cutting_memo(prices_table, mem, n);
    auto end_memo = chrono::steady_clock::now();
    cout << "Resultado con Algoritmo Recursivo con Memoización: " << result_memo << endl;
    cout << "Tiempo con Algoritmo Recursivo con Memoización: "
         << chrono::duration_cast<chrono::nanoseconds>(end_memo - start_memo).count()
         << " nanosegundos\n";

    return 0;
}