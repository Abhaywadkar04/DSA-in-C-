class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = 0;
        vector<int> nums2;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums2.empty() || nums2.back() != nums[i]) {
                nums2.push_back(nums[i]);
                num++;
            }
        }

           for (int i = 0; i < nums2.size(); i++) {
            nums[i] = nums2[i];
        }
        
        return num;
    }
};