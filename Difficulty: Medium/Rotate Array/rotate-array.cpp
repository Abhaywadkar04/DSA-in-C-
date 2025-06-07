class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;  // ✅ in case d > n

        if (d == 0 || n <= 1) return;

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = arr[(i + d) % n]; 
        }

        arr = ans;
    }
};
