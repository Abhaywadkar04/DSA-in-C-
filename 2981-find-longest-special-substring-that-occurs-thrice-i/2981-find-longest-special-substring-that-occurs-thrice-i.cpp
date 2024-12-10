class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mpp;
        for(int i = 0;i<s.length();i++){
            string str;
            for(int j = i;j<s.length();j++){
                str+= s[j];
                unordered_set<char>set(str.begin(),str.end());
                if(set.size()==1){
                  mpp[str]++;
                }

            }
        }
        int ans = -1;
        for(auto it:mpp){
            int x = it.first.length();
            if(it.second>=3){
               ans = max(ans,x);
            }
        }
        return ans;
    }
};