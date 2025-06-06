class Solution {
  public:
    int missingNum(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1; 
    }
};
