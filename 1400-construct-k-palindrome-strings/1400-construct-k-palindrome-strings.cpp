class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>map;

        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int count=0;
        for(auto &[c,freq]:map){
            if(freq%2==1){
                    count++;
            }
        }

        return(count<=k && k<=s.size());
    }
};