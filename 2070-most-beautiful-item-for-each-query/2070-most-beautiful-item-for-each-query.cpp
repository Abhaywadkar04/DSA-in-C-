#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
        std::sort(items.begin(), items.end());

        int maxBeauty = 0;
        for (auto& item : items) {
            maxBeauty = std::max(maxBeauty, item[1]);
            item[1] = maxBeauty;
        }

        std::vector<int> ans;
        for (int i : queries) {
            int left = 0, right = items.size() - 1;
            int bestBeauty = 0;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= i) {
                    bestBeauty = items[mid][1];
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            ans.push_back(bestBeauty);
        }

        return ans;
    }
};
