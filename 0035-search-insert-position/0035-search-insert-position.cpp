class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
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



         // Target not found
        int i=0;
        while(i<n){
            if(nums[i]<target){
                i++;
            }
            else {
                return i;
            }
        }
        return i;
    }
};