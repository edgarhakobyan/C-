#include <iostream>
#include <chrono>

// Recursion
int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n -2);
}

// Store (Memoize)
int fibMemo(int n, int memo[]) {
    if (memo[n] != 0) {
        return memo[n];
    }
    int result = 0;
    if (n == 1 || n == 2) {
        result = 1;
    } else {
        result = fibMemo(n -1, memo) + fibMemo(n -2, memo);
    }
    memo[n] = result;
    return result;
}

int fibMemoDemo(int n) {
    int* memo = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        memo[i] = 0;
    }
    return fibMemo(n, memo);
}

// Bottom Up
int fibBottomUp(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int* bottomUp = new int[n];
    bottomUp[0] = 1;
    bottomUp[1] = 1;
    for (int i = 2; i < n; ++i) {
        bottomUp[i] = bottomUp[i - 1] + bottomUp[i - 2];
    }
    int result = bottomUp[n - 1];
    delete [] bottomUp;
    return result;
}

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    int result = fib(35);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Recursion: Fib number of 35 is: " << result << ", with duration: " << duration << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    int resultMemo = fibMemoDemo(35);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Store method: Fib number of 35 is: " << resultMemo << ", with duration: " << duration << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    int resulBottomUp = fibBottomUp(35);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "Bottom Up: Fib number of 35 is: " << resulBottomUp << ", with duration: " << duration << std::endl;
    return 0;
}