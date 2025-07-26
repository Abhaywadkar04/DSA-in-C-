class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;

        int cnt=0;
        for (int num : nums) {
            if (num >= 0) {
                s.insert(num);
            }else{
                cnt++;
            }
        }
        int maxi=INT_MIN;
        if(cnt==nums.size()){
            for(int i =0;i<nums.size();i++){
                if(maxi<nums[i]){
                    maxi=nums[i];
                }
            }
            return maxi;
        }

        int ans = 0;
        for (int num : s) {
            ans += num;
        }

        return ans;
    }
};
