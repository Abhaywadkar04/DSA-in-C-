class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>map;
        for(int i= 0;i<arr.size();i++){
            map[arr[i]]++;
        }
        
        int s=arr.size()/2;
        
        for(auto i: map){
            if(i.second>s){
                return i.first;
            }
        }
        return -1;
    }
};