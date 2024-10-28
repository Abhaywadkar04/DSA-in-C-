class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long >s(nums.begin(),nums.end());
        int longestStreak=0;
        int count=-1;
        for( auto num:s){

            count=0;
            while(s.find(num)!=s.end()){
                count++;
                num *= num;
            }

            longestStreak = max(longestStreak, count); 
        }
        return longestStreak >1?longestStreak:-1;
    }
};