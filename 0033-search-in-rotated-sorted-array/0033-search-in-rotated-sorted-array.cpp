class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size(); // e is set to nums.size() instead of nums.size() - 1

        while (s < e) { // Condition changed to s < e
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[s] <= nums[mid]) {
                // Check if the target is within the left half
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid; // Move e to mid
                } else {
                    s = mid + 1; // Move s to mid + 1
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // Check if the target is within the right half
                if (nums[mid] < target && target <= nums[e-1]) { // Adjust comparison to nums[e-1]
                    s = mid + 1; // Move s to mid + 1
                } else {
                    e = mid; // Move e to mid
                }
            }
        }

        return -1; // Target not found
    }
};
