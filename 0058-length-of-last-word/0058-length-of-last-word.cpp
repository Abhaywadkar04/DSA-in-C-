class Solution {



public:
    int lengthOfLastWord(string s) {


        int n=s.length();
        char space=' ';
        int ans;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=space){
                ans=i;
                break;
            }
        }
        int count =0;
        for(int i=ans;i>=0;i--){
            if(s[i]== space){
                break;
            }

            count++;
        }

        return count;
        
    }
};