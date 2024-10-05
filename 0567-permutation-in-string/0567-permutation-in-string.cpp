class Solution {
public:
    bool checkInclusion(string p, string s)
    {
        unordered_map<char,int>m;
        int n=s.length();
        int k=p.length();
        for(auto i:p)
            m[i]++;
        int c=m.size();
        int i=0,j=0;
        while(j<n)
        {
            if(m.count(s[j]))
            {
                m[s[j]]--;
               if(m[s[j]]==0)
                   c--;
            }
            
            if((j-i+1) <k)
                j++;
            
            else if((j-i+1) ==k)
            {
                if(c==0)
                    return true;
                
                if(m.count(s[i]))
                {
                  m[s[i]]++;
                    
                  if (m[s[i]]==1)
                  c++;
                        
                }
                          i++;
                          j++;
            }
           
        }
           return false;
        
    }
};