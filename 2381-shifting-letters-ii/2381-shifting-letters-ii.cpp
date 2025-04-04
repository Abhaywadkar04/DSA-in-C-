class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i=0;i<shifts.size();i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction == 1) {
                dp[start]++;
                dp[end + 1]--;
            } else {
                dp[start]--;
                dp[end + 1]++;
            }
        }

        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += dp[i];
            int currentPos = s[i] - 'a';
            int newPos = (currentPos + prefixSum % 26 + 26) % 26;
            s[i] = 'a' + newPos;
        }

        return s;
    }
};