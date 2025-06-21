class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  

        int cnt = 1;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] - nums[i] > k) {
                cnt++;
                i = j;
            }
        }

        return cnt;
    }
};
