class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> lineSwip;

        for (auto &event : events) {
            int start = event[0];
            int end = event[1];
            int value = event[2];
            lineSwip.push_back({start, 1, value});
            lineSwip.push_back({end+1, -1, value});
        }

        sort(lineSwip.begin(), lineSwip.end());

        int maxSeen = 0;
        int maxSum = 0;

        for (auto &event : lineSwip) {
            if (event[1] == 1) {
                maxSum = max(maxSum, maxSeen + event[2]);
            }
            if (event[1] == -1) {
                maxSeen = max(maxSeen, event[2]);
            }
        }

        return maxSum;
    }
};
