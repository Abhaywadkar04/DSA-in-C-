#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int left = prefixMax[i];
            int right = suffixMax[i];
            sum += min(left, right) - height[i];
        }

        return sum;
    }
};
