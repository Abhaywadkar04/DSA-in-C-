class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }

private:
    void generateSubsets(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Base case: if we've considered all elements
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }

        // Exclude the current element and move to the next
        generateSubsets(index + 1, nums, currentSubset, result);

        // Include the current element in the subset
        currentSubset.push_back(nums[index]);

        // Move to the next element after including the current one
        generateSubsets(index + 1, nums, currentSubset, result);

        // Backtrack and remove the current element before going back
        currentSubset.pop_back();
    }
};
