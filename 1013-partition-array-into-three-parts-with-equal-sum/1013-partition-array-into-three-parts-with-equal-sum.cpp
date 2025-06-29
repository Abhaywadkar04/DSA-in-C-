class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        sum=sum/3;

        int dummy=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            dummy+=arr[i];


            if(dummy==sum){
                cout<<dummy;
                count++;
                dummy=0;
            }
        }
        if(count>=3){
            return true;
        }
        return false;
    }
};