class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<int>ans;
        int dum=0;
        for(int i=0;i<nums.size();i++){
            
            if(dum>sum){
                return ans;
            }
            else{
                sum=sum-nums[i];
            dum+=nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};