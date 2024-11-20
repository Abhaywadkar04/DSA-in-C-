#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);

        // Count occurrences of 'a', 'b', and 'c' in the string
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // If any character count is less than k, it's not possible to satisfy the condition
        if (*min_element(count.begin(), count.end()) < k) {
            return -1;
        }

        int size = INT_MAX;
        int l = 0;
        int n = s.size();

        // Use a sliding window to find the minimum substring to remove
        for (int r = 0; r < n; r++) {
            count[s[r] - 'a']--;
            
            // While the current window is invalid (any count < k), shrink the window
            while (*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }
            
            // Update the minimum size
            size = min(size, n - (r - l + 1));
        }

        return size;
    }
};
