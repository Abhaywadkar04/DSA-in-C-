class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count=0;

        for(char i=0;i<words.size();i++){

            for(char j=i+1;j<words.size();j++){
                if(words[j].starts_with(words[i]) && words[j].ends_with(words[i])){
                    count++;
                }
            }

        }
        return count;
    }
};