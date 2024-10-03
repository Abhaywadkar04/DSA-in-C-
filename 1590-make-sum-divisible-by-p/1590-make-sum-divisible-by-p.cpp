#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
            totalSum %= k;
        }

        if (totalSum == 0) return 0;  // Already divisible by k, no need to remove subarray

        int targetRemainder = totalSum % k;
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;  // To handle subarrays starting from index 0

        int currentPrefixSum = 0;
        int minLength = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            currentPrefixSum = (currentPrefixSum + nums[i]) % k;
            if (currentPrefixSum < 0) currentPrefixSum += k;

            int neededRemainder = (currentPrefixSum - targetRemainder + k) % k;

            // Check if we've seen the needed remainder before
            if (remainderIndex.find(neededRemainder) != remainderIndex.end()) {
                minLength = min(minLength, i - remainderIndex[neededRemainder]);
            }

            // Update the map with the current remainder
            remainderIndex[currentPrefixSum] = i;
        }

        // If we found a valid subarray, return its length, otherwise return -1
        return (minLength == INT_MAX || minLength == nums.size()) ? -1 : minLength;
    }
};
