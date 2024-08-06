class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> map(26, 0);

        // Count frequencies of each character
        for (char c : word) {
            map[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(map.begin(), map.end(), greater<int>());

        int ans = 0;
        int push = 1;
        int keycount = 0;

        // Calculate minimum pushes required
        for (int i = 0; i < 26 && map[i] > 0; i++) {
            ans += map[i] * push;
            keycount++;

            if (keycount % 8 == 0) {
                push++;
            }
        }

        return ans;
    }
};
