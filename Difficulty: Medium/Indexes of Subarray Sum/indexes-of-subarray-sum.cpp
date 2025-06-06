class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        int sum = 0;

        while (r < arr.size()) {
            sum += arr[r];

            while (sum > target && l <= r) {  
                sum -= arr[l];
                l++;
            }

            if (sum == target) {
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }

            r++;
        }

        return {-1};
    }
};
