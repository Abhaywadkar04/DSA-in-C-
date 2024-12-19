class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<int>rightMin(arr.size()+1);

        rightMin[arr.size()]=INT_MAX;
    
        for(int i=arr.size()-1;i>=0;i--){
            
            rightMin[i]=min(arr[i],rightMin[i+1]);



        }
        int leftMax=INT_MIN;
        int count=0;

        for(int i=0;i<arr.size();i++){
            leftMax=max(arr[i],leftMax);
            if(leftMax<=rightMin[i+1]){
                count++;
            }
        }


return count;

        
    }
};