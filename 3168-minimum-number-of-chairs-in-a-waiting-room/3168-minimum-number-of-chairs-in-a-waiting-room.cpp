class Solution {
public:
    int minimumChairs(string s) {
        int count=0;
        int answer=0;
        for(char i = 0 ;i < s.size();i++){
            
            if(s[i]=='E'){
                count++;
                answer =max(count,answer);
            }
            else{
                count--;
            }


        }
        return answer;
    }
};