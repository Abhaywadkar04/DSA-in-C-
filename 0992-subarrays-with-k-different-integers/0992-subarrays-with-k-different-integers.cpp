#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int checkArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int, int> map;
        int count = 0;

        while (r < n) {
            map[nums[r]]++;

            while (map.size() > k) {
                map[nums[l]]--;
                if (map[nums[l]] == 0) {
                    map.erase(nums[l]);
                }
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return checkArray(nums, k) - checkArray(nums, k - 1);
    }
};
