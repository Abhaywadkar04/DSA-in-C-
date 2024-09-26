class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1); // Memoization array
        return climbStairsHelper(n, memo);
    }

private:
    int climbStairsHelper(int n, vector<int>& memo) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Check if already computed
        if (memo[n] != -1) return memo[n];

        // Compute and store the result in memo
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
};
