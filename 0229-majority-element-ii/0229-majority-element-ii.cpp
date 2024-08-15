#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> nums2;
        vector<int> nums3;

        // Count the frequency of each element
        for(int i = 0; i < nums.size(); i++) {
            nums2[nums[i]]++;
        }

        int n = nums.size() / 3;

        
        for(auto it = nums2.begin(); it != nums2.end(); ++it) {
            if(it->second > n) {
                nums3.push_back(it->first);
            }
        }

        return nums3;
    }
};
