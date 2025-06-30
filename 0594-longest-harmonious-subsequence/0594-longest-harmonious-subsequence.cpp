#include <vector>
#include <climits>
using namespace std;

class Solution {
    void generateSubsequences(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& result) {
        if (index == arr.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(arr[index]);
        generateSubsequences(index + 1, arr, temp, result);

        temp.pop_back();
        generateSubsequences(index + 1, arr, temp, result);
    }

    int maxElement(vector<int> arr) {
        int n = INT_MIN;
        for (auto i : arr) {
            if (i > n) {
                n = i;
            }
        }
        return n;
    }

    int minElement(vector<int> arr) {
        int n = INT_MAX;
        for (auto i : arr) {
            if (i < n) {
                n = i;
            }
        }
        return n;
    }

public:
    int findLHS(vector<int>& nums) {
        vector<vector<int>> subsequences;
        vector<int> temp;

        generateSubsequences(0, nums, temp, subsequences);

        int ans = 0;
        for (auto i : subsequences) {
            if (i.size() == 0) continue; 
            int maxi = maxElement(i);
            int mini = minElement(i);

            if (maxi - mini == 1) {
                ans = max(ans, (int)i.size());  
            }
        }
        return ans;
    }
};
