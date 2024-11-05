class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                changes++;
            }
        }

        return changes;
    }
};
