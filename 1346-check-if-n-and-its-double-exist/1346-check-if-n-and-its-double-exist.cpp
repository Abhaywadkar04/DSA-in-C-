class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        sort(arr.begin(),arr.end());


        for(int j=0;j<arr.size();j++){
            for(int i=0;i<arr.size();i++){
                if(i!=j){
                    if(arr[j]*2==arr[i]){
                        return true;
                    }
                }
            }

        }

        return false;
        
    }
};