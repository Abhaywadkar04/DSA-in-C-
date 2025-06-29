class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        
        if(nums.size()%2!=0)return false;

        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;

                if(count>1){
                    return false;
                }
            }
            else{
                count=0;

            }
        }
        return true;
    }
};