class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int prefsum=0;
        int sufsum=0;
        for(int i=0;i<n;i++){
            prefix[i]=prefsum;
            prefsum+=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            suffix[i]=sufsum;
            sufsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]){
                return i;
            }
        }
        return -1;
    }
};