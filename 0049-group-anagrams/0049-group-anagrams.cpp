class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>mp;

        for(auto word:strs){
            string x=word;
            sort(x.begin(),x.end());
            mp[x].push_back(word);
        }

        vector<vector<string>>s;

        for(auto X:mp){
            s.push_back(X.second);
        }


        return s;
        
    }
};