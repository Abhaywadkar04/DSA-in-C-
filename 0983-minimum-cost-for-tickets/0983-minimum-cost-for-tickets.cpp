class Solution {
    int solve(vector<int>&days,vector<int>& costs,vector<int>& dp,int index){

        if(index >= days.size()){
            return 0;
        }

        if(dp[index]!= -1){
            return dp[index];
        }

        //1 day
        int option1=costs[0]+solve(days,costs,dp,index+1);

        //7 days
        int i;
        for( i=index;i<days.size() && days[i]<days[index]+7;i++);
        int option2=costs[1]+solve(days,costs,dp,i);

        //30 days

        for(i=index;i<days.size() && days[i]<days[index]+30;i++);
        int option3=costs[2]+solve(days,costs,dp,i);


        dp[index]=min(option1,min(option2,option3));
        return dp[index];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(days.size(),-1);
        return solve(days,costs,dp,0);
    };
};