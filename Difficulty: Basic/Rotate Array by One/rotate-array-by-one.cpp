class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n); 

        for (int i = 0; i < n; i++) {
            ans[(i + 1) % n] = arr[i];  
        }

        arr = ans;  
    }
};
