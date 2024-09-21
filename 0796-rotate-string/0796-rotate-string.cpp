class Solution {
public:
    bool rotateString(string s, string goal) {

        

        if(s.length() != goal.length()) return false;
        string check=goal+goal;

        if(check.find(s)!=string::npos){
            return true;
        }
        else{
            return false;
        }
    }
};