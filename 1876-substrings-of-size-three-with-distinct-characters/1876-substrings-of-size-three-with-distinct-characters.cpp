class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3){
            return 0;
        }

        int cnt = 0;

        for(int i = 0; i <= s.size() - 3; i++){
            if(s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]){
                cnt++;
            }
        }
        return cnt;
    }
};