class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int mid=0;
        int low=0;
        int high=arr.size()-1;
        
        
       while(mid<=high){
           if(arr[mid]==0){
               swap(arr[low],arr[mid]);
               low++;
               mid++;
           }
           else if(arr[mid]==1){
               mid++;
           }
           else{
               
               swap(arr[mid],arr[high]);
               high--;
           }
       }
        
        
        
        
        
    }
};