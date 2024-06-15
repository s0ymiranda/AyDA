#include <iostream>
#include <unordered_map>
#include <chrono>

// Basic Recursive Algorithm
unsigned long long fibonacciRecursive(int n)
{
    if (n <= 1 )
    {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


// Recursive Algorithm with Memoization
std::unordered_map<int, unsigned long long> memo;

unsigned long long fibonacciMemoization(int n)
{
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }
    if (n <= 1)
    {
        return n;
    }
    unsigned long long result = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);
    memo[n] = result;
    return result;
}

// Bottom-Up Algorithm
unsigned long long fibonacciBottomUp(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long prev2 = 0;
    unsigned long long prev1 = 1;
    unsigned long long current;

    for (int i = 2; i <= n; ++i)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}