class Solution {
    void permutation(vector<int>&nums,vector<vector<int>>&ans,vector<int>s,int freq[]){
        if(s.size()==nums.size()){
            ans.push_back(s);
            return;
        }


        for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            freq[i]=1;
        
        s.push_back(nums[i]);
        permutation(nums,ans,s,freq);
        freq[i]=0;
        s.pop_back();
        }}}
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>s;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;

        
         permutation(nums,ans,s,freq);
        return ans;
        
    }
};