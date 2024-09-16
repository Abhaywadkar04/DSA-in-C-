class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int>minutes;
        int mini=INT_MAX;

        for(const auto&val :timePoints){
            int hr=10*(val[0]-'0')+(val[1]-'0');
            int min=10*(val[3]-'0')+(val[4]-'0');
            minutes.push_back(60*hr+min);
        }
        

        sort(minutes.begin(),minutes.end());
        int n=minutes.size();
        
        for(int i=1;i<n;i++){
            mini=min(mini,minutes[i]-minutes[i-1]);

            
        }

        mini=min(mini,1440-(minutes[n-1]-minutes[0]));


        return mini;


    }
};