class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_map<int, int> map;
        long long sum = 0, ans = 0;

        while (r < nums.size()) {
            map[nums[r]]++;
            sum += nums[r];
            r++;

            while (r - l > k) {
                map[nums[l]]--;
                if (map[nums[l]] == 0) {
                    map.erase(nums[l]);
                }
                sum -= nums[l];
                l++;
            }

            if (r - l == k && map.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
