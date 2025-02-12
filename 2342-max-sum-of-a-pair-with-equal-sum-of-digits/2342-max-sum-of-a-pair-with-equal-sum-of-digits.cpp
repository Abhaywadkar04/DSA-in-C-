class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxi[82]={0};

        int ans =-1;
        
        for(int x: nums){
            int sum = 0;
            int temp=x;
            while(temp!=0){
                sum+=temp%10;
                temp /=10;
            }

            if(maxi[sum]!=0){
                ans= max(ans,maxi[sum]+x);
            }
            
                maxi[sum]=max(maxi[sum],x);
            
        }return ans;


    }
};