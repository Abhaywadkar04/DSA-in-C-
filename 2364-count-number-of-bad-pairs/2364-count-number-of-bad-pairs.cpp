class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        long long n = nums.size();
        long long total_pairs = (n * (n - 1)) / 2; 

        long long good_pairs = 0;
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            good_pairs += freq[key]; 
            freq[key]++; 
        }

        return total_pairs - good_pairs; 
    }
};
