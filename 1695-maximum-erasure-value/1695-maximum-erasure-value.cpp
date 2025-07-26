class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int l=0;
        int r=0;
        unordered_map<int,int>mp;
        int sum=0;
        int maxSum=0;
        while(r<nums.size()){

            sum+=nums[r];
            mp[nums[r]]++;

            while(mp[nums[r]]>1){

                sum-=nums[l];
                mp[nums[l]]--;
                l++;
            }
            maxSum = max(maxSum, sum);
            r++;
        }
        return maxSum;
    }
};