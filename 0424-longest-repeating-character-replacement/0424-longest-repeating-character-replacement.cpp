class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int l = 0;
        int maxFreq = 0;
        int maxLength = 0;
        int n = s.length();

        for (int r = 0; r < n; r++) {
            map[s[r]]++;
            
            maxFreq = max(maxFreq, map[s[r]]);
            
            while ((r - l + 1) - maxFreq > k) {
                map[s[l]]--;
                l++;
            }
            
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};
