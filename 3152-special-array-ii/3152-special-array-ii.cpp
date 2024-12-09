#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<bool> ans(m);
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i] = 1 + prefix[i - 1];
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (int idx = 0; idx < m; idx++) {
            int s = queries[idx][0];
            int e = queries[idx][1];
            ans[idx] = (prefix[e] - prefix[s] == 0);
        }

        return ans;
    }
};
