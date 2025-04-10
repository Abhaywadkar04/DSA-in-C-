class Solution {
    int n;
    int dp[1001][1001]; 

    int solve(vector<vector<int>>& pairs, int prev, int current) {
        if (current >= n) return 0;

        if (dp[prev + 1][current] != -1) return dp[prev + 1][current];

        int taken = 0;
        if (prev == -1 || pairs[prev][1] < pairs[current][0]) {
            taken = 1 + solve(pairs, current, current + 1);
        }

        int not_taken = solve(pairs, prev, current + 1);

        return dp[prev + 1][current] = max(taken, not_taken);
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); 
        n = pairs.size();

        memset(dp, -1, sizeof(dp));

        return solve(pairs, -1, 0);
    }
};
