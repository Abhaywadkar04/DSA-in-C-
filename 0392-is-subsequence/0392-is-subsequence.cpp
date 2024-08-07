class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int count = m;
        int n = t.length();
        
        for (int i = 0, j = 0; i < m && j < n;) {
            if (s[i] == t[j]) {
                count--;
                i++; // Move to the next character in s
            }
            j++; // Always move to the next character in t
        }
        
        // Check if all characters in s were found in t in order
        return count == 0;
    }
};
