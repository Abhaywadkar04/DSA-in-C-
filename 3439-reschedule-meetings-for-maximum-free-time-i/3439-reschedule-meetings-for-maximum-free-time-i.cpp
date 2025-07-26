class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        vector<int>diff;
        diff.push_back(startTime[0]-0);
        for(int i=1;i<n;i++)
        {
            diff.push_back(startTime[i]-endTime[i-1]);
        } 
        diff.push_back(eventTime-endTime[n-1]);

        int i = 0;
        int j = 0;
        int sum = 0;
        int mxSum = 0;
        n = diff.size();

        while(j<n)
        {
            sum+=diff[j];
            if(j-i+1>k+1)
            {
                sum-=diff[i];
                i++;
            }
            mxSum = max(sum, mxSum);
            j++;
        }

        return mxSum;
    }
};