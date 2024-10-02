#include <vector>
#include <set>

class Solution {
    void permutation(vector<int>& nums, vector<int>& s, set<vector<int>>& uniquePerms, int frq[]) {
        if (s.size() == nums.size()) {
            uniquePerms.insert(s);  // Add the current permutation to the set
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!frq[i]) {  // If nums[i] hasn't been used in the current permutation
                s.push_back(nums[i]);  // Add nums[i] to the current permutation
                frq[i] = 1;  // Mark nums[i] as used
                permutation(nums, s, uniquePerms, frq);  // Recurse to generate next elements
                frq[i] = 0;  // Backtrack: Unmark nums[i]
                s.pop_back();  // Remove nums[i] from the current permutation
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> uniquePerms;  // To store unique permutations
        vector<int> s;
        int frq[nums.size()];
        std::fill(frq, frq + nums.size(), 0);  // Initialize frequency array to 0

        permutation(nums, s, uniquePerms, frq);  // Generate permutations

        // Convert the set to a vector of vectors
        vector<vector<int>> ans(uniquePerms.begin(), uniquePerms.end());
        return ans;  // Return the unique permutations
    }
};
