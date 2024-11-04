#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prefixmin(n), suffixmin(n);

        prefixmin[0] = -1;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                j = min(j, prefixmin[j]);
            }
            prefixmin[i] = j;
        }

        suffixmin[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) {
                j = max(j, suffixmin[j]);
            }
            suffixmin[i] = j;
        }

        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, heights[i] * (suffixmin[i] - prefixmin[i] - 1));
        }

        return maxi;
    }
};
