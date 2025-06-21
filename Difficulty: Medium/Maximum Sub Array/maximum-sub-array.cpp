// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        long long maxSum = -1, currSum = 0;
        int maxStart = -1, maxLen = 0;
        int start = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= 0) {
                currSum += arr[i];
                if (currSum > maxSum || (currSum == maxSum && (i - start + 1 > maxLen))) {
                    maxSum = currSum;
                    maxStart = start;
                    maxLen = i - start + 1;
                }
            } else {
                currSum = 0;
                start = i + 1;
            }
        }

        if (maxStart == -1)
            return {-1};  // All elements are negative

        return vector<int>(arr.begin() + maxStart, arr.begin() + maxStart + maxLen);
    }
};
