class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>map1;
                vector<string>answer;

        for(const string& word:words2){
            unordered_map<char,int>temp;
            for(auto i:word){
                temp[i]++;
            }

        for(auto[c,freq] : temp){
            map1[c]=max(map1[c],freq);
        }
   }

        
        for(auto word:words1){
            unordered_map<char,int>map2;
            for(char c:word){
                map2[c]++;
            }

        bool check=true;

        for(auto[c,freq]:map1){
            if(map2[c]<freq){
                check=false;
                break;
            }
        }

            if(check){
                answer.push_back(word);
            }
        }     
        return answer;
    }
};