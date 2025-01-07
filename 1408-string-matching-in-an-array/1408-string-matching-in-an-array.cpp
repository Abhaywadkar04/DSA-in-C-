class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>ans;
        for(auto i:words){

            for(auto j:words){
                if(j.find(i)!=string::npos && j!=i){
                    ans.insert(i);
                }
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};