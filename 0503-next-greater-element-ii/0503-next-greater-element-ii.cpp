#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr(nums.size(), -1);
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) { 
                long long index = (i + j) % nums.size();
                if (nums[index] > nums[i]) {
                    arr[i] = nums[index];
                    break; 
                }
            }
        }
        
        return arr;
    }
};
