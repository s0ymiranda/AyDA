#include "fibonacci.hpp"
int main(int argc, char *argv[]) {

    int n = 1;

    if (argc > 1) {
        try {
            n = std::stoi(argv[1]);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << argv[1] << std::endl;
            return 1;
        }
    }

    // Timing the Basic Recursive Algorithm
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Fibonacci(" << n << ") = " << fibonacciRecursive(n) << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by Basic Recursive: " << duration.count() << " nanoseconds" << std::endl;

    // Timing the Recursive Algorithm with Memoization
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Fibonacci(" << n << ") = " << fibonacciMemoization(n) << std::endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by Recursive with Memoization: " << duration.count() << " nanoseconds" << std::endl;

    // Timing the Bottom-Up Algorithm
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Fibonacci(" << n << ") = " << fibonacciBottomUp(n) << std::endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by Bottom-Up: " << duration.count() << " nanoseconds" << std::endl;

    return 0;
}