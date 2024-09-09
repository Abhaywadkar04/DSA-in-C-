#include <iostream>

class Solution {
public:
    // Function to perform modular exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;
        
        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp / 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7; // A large prime number for modulus

        // Calculate counts of even and odd indices
        long long evenCount = (n + 1) / 2; // Number of even indices
        long long oddCount = n / 2; // Number of odd indices

        // Calculate powers using modular exponentiation
        long long evenPower = modPow(5, evenCount, MOD);
        long long oddPower = modPow(4, oddCount, MOD);

        // Calculate the final result with modulo
        long long ans = (evenPower * oddPower) % MOD;

        return static_cast<int>(ans); // Cast to int if within range
    }
};

