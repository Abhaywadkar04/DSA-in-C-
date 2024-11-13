class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (auto& i : intervals) {
            vector<int>& last = ans.back();

            if (last[1] >= i[0]) {
                last[1] = max(last[1], i[1]);
            } else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
