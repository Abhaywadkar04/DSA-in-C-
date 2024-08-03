class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k is greater than the size of the vector

        if (k > 0) {
            // Reverse the last k elements
            std::reverse(nums.end() - k, nums.end());
            // Reverse the first n-k elements
            std::reverse(nums.begin(), nums.end() - k);
            // Reverse the entire vector
            std::reverse(nums.begin(), nums.end());
        }
    }
};
