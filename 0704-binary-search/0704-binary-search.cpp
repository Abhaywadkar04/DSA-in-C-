#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) { // Correct condition to include s == e case
            int mid = s + (e - s) / 2; // Recalculate mid in each iteration
            
            if (target == nums[mid]) {
                return mid; // Target found
            } 
            else if (target > nums[mid]) {
                s = mid + 1; // Search in the right half
            } 
            else {
                e = mid - 1; // Search in the left half
            }
        }

        return -1; // Target not found
    }
};
