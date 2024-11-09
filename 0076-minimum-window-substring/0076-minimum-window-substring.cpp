class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int minLen=INT_MAX;
        int sIndex=-1;
        int cnt=0;
        int m=s.length();
        int n=t.length();

        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }

        while(r<m){

            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;


            while(cnt==n){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sIndex=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        
        return minLen == INT_MAX ? "":s.substr(sIndex,minLen);
    }
};