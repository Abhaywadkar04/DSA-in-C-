class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX,n=nums.size();
        set<int> st;
       for(int i=x;i<n;i++){
            st.insert(nums[i-x]);
            auto itr = st.lower_bound(nums[i]);
            if(itr!=st.end()) ans =min(ans,abs(nums[i]-*itr));
            if(itr!=st.begin()) {
                 itr--;
                 ans =min(ans,abs(nums[i]-*itr));
            }
       } 
       return ans;   
    }
};