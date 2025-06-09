// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        stack<int>stk;
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                stk.push(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        arr=ans;
    }
};