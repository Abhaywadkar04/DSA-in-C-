class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        int size=skill.size();
        

        sort(skill.begin(),skill.end());

        int i=0;
        int j=size-1;
        int dummy=skill[i]+skill[j];
        int ans=0;
        while(i<j){
            
            int sum=skill[i]+skill[j];
            if(sum!=dummy){
                return -1;
            }

            ans += skill[i]*skill[j];
            i++;
            j--;

        }

        return ans;
        
    }
};