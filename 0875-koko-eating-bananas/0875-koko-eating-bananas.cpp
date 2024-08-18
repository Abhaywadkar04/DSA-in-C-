

class Solution {
    int hoursRequired(const vector<int>& piles, int speed) {
        int hours = 0;
        for (int pile : piles) {
            hours += ceil(static_cast<double>(pile) / speed);
        }
        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        
        int start = 1;
        int end = maxPile;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            int hours = hoursRequired(piles, mid);
            
            if (hours <= h) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};
