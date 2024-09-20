class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map1,map2;

        if(s.length()!=t.length())return false;

        for(int i=0;i<s.length();i++){

            char S=s[i];
            char T=t[i];

            if(map1.find(S)!=map1.end()){
                if(map1[S]!=T)return false;
            }
            else{
                map1[S]=T;
            }
            if(map2.find(T)!=map2.end()){
                if(map2[T]!=S)return false;
            }
            else{
                map2[T]=S;
            }

        }    
        return true;    
    }
};