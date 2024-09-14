class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxElement = *max_element(begin(nums), end(nums));

        int answer = 1, count = 0 ;
        for(auto val:nums)
        {
            if(val == maxElement) count += 1;
            else count = 0;
            answer = max(answer, count);
        }
        return answer;
    }
};