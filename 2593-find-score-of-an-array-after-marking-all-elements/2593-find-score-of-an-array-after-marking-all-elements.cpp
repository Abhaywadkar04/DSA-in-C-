#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        
        for (int i = 0; i < n; ++i) {
            minHeap.emplace(nums[i], i);
        }
        
        vector<bool> visited(n, false);
        
        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();
            
            if (visited[index]) continue;
            
            score += value;
            
            visited[index] = true;
            if (index > 0) visited[index - 1] = true;
            if (index < n - 1) visited[index + 1] = true;
        }
        
        return score;
    }
};
