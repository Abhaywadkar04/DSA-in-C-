class Solution {
private:
    bool check(char s){
        if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')){
            return 1;
        }
        else{
            return 0;
        }
    }

    char lowercase(char a){
        if((a >= 'a' && a <= 'z') || (a >= '0' && a <= '9')){
            return a;
        }
        else{
            a = a - 'A' + 'a';
        }
        return a;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int j = 0; j < s.length(); j++){
            if(check(s[j])){
                temp.push_back(s[j]);
            }
        }

        for(int i = 0; i < temp.length(); i++){
            temp[i] = lowercase(temp[i]);
        }
        
        int start = 0;
        int e = temp.length() - 1;
        while(start <= e){
            if(temp[start] != temp[e]){
                return 0;
            }
            else{
                start++;
                e--;
            }
        }
        return 1;
    }
};