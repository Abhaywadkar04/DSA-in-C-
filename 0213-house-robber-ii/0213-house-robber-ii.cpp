class Solution {
    int t[101];

    int solve(vector<int>& nums, int end, int i) {
        if (i > end) return 0;
        if (t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, end, i + 2);
        int skip = solve(nums, end, i + 1);
        return t[i] = max(steal, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int skipLast = solve(nums, n - 2, 0);  // rob from house 0 to n-2

        memset(t, -1, sizeof(t));
        int skipFirst = solve(nums, n - 1, 1); // rob from house 1 to n-1

        return max(skipLast, skipFirst);
    }
};
