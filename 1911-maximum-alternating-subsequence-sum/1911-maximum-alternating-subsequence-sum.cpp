class Solution {
    long long t[100001][2]; // [index][flag] → 0 for false, 1 for true

    long long solve(vector<int>& nums, int n, int i, bool flag) {
        if (i >= n) return 0;

        if (t[i][flag] != -1) return t[i][flag];

        long long skip = solve(nums, n, i + 1, flag);

        long long val = nums[i];
        if (!flag) val = -val; // subtract if it's a minus turn

        long long take = val + solve(nums, n, i + 1, !flag);

        return t[i][flag] = max(take, skip);
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0, true); // start with + sign
    }
};
