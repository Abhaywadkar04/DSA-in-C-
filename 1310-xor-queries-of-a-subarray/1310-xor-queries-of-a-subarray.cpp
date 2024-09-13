class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            int xor_sum = 0;
            for (int i = left; i <= right; ++i) {
                xor_sum ^= arr[i];
            }
            result.push_back(xor_sum);
        }
        return result;
    }
};
