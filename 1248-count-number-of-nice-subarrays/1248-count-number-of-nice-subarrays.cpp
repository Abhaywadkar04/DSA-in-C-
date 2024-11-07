class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int count = 0, oddCount = 0;
        for (r = 0; r < n; r++) {
            if (nums[r] % 2 != 0) {
                k--;
                oddCount = 0;
            }

            while (k == 0) {
                if (nums[l] % 2 != 0) {
                    k++;
                }
                oddCount++;
                l++;
            }

            count += oddCount;
        }

        return count;
    }
};
