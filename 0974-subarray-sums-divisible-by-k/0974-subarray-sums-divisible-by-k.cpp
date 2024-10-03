class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>map;
        map[0]=1;
        int prefix=0;
        int count=0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int remainder = prefix % k;
            if (remainder < 0) remainder += k;
            count += map[remainder];
            map[remainder]++;
        }

        return count;
    }
};