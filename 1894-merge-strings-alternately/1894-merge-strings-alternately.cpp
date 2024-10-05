class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string s="";
        int n=word1.size();
        int m =word2.size();
        int minimum=min(n,m);

        for(int i=0;i<minimum;i++){
            s.push_back(word1[i]);
            s.push_back(word2[i]);


        }

        if(n>minimum){
            s.append(word1.substr(minimum));

        }
        if(m>minimum){
            s.append(word2.substr(minimum));

        }
        
        return s;
    }
};