class Solution {
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int prev) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        int take = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }

        int skip = solve(nums, i + 1, prev);

        return dp[i][prev + 1] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1)); 
        return solve(nums, 0, -1);
    }
};
