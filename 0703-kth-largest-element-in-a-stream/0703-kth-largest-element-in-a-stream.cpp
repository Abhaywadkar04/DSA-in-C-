#include <vector>
#include <queue>
#include <algorithm>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        // Create a min-heap for the k largest elements
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]); // Use the add method to maintain the heap
        }
    }
    
    int add(int val) {
        pq.push(val); // Add new value to the min-heap
        if (pq.size() > k) {
            pq.pop(); // Remove the smallest element if size exceeds k
        }
        return pq.top(); // The top of the heap is the k-th largest element
    }

private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Min-heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
