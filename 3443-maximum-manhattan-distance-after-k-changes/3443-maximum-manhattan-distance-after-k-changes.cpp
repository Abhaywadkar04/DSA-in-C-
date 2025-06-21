class Solution {
public:
    int maxDistance(string s, int k) {
        int sth=0;
        int est=0;
        int wst=0;
        int nth=0;
        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s[i] == 'E') est++;
else if(s[i] == 'W') wst++;
else if(s[i] == 'N') nth++;
else if(s[i] == 'S') sth++;


            int curman=abs(sth-nth) + abs(wst-est);
            int steps=i+1;

            int diff=steps-curman;
            int extra=0;
            if(diff!=0){
          extra=min(2*k,diff);

            }
            int finalans=extra+curman;

            ans=max(finalans,ans);
        }
        return ans;

    }
};