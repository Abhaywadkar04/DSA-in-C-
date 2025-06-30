class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if(is_sorted(nums.begin(), nums.end()) || is_sorted(nums.begin(), nums.end(),greater<int>())){
            return true;
        }
        
            
        return false;
    }
};