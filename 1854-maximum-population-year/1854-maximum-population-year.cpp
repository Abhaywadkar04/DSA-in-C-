class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end());
        int start = logs[0][0];
        int end = logs[logs.size() - 1][1];

        int maxCount = 0;
        int answer = 0;

        for (int i = start; i < end; i++) {
            int count = 0;
            for (auto j : logs) {
                int birth = j[0];
                int death = j[1];

                if (i >= birth && i < death) {
                    count++;
                }
            }

            if (count > maxCount) {
                maxCount = count;
                answer = i;
            }
        }

        return answer;
    }
};
