class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       stringstream string1(s1);
    stringstream string2(s2);
        vector<string>ans;

        unordered_map<string,int>map;
        string word;
        while(string1 >>word ){
            map[word]++;
        }
        while(string2 >>word ){
            map[word]++;
        }

        for(auto arrow:map){
            if(arrow.second ==1){
                ans.push_back(arrow.first);

            }
        }

        return ans;
        
    }
};