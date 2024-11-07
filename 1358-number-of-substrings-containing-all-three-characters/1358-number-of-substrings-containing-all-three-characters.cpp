class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, count = 0;
        int n = s.length();
        unordered_map<char, int> map;

        for (int r = 0; r < n; r++) {
            map[s[r]]++;

            while (map['a'] > 0 && map['b'] > 0 && map['c'] > 0) {
                count += (n - r);  
                map[s[l]]--;      
                l++;
            }
        }
        
        return count;
    }
};
