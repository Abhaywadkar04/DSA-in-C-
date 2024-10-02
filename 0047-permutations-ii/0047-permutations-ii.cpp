class Solution {
    void permutation(vector<int>&nums,vector<int>&s,vector<vector<int>>&ans,int frq[]){

        if(s.size()==nums.size()){
            ans.push_back(s);
            return;
            
        }

        for(int i=0;i<nums.size();i++){
            if(!frq[i]){
                s.push_back(nums[i]);
                frq[i]=1;
                permutation(nums,s,ans,frq);
                frq[i]=0;
                s.pop_back();
            }
        }


    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>s;
        int frq[nums.size()];
        for(int i=0;i<nums.size();i++)frq[i]=0;
        permutation(nums,s,ans,frq);
        std::sort(ans.begin(), ans.end());

    auto last = std::unique(ans.begin(), ans.end());

    ans.erase(last, ans.end());
    return ans;
        
    }
};