class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = arr.size();
        int count=0;
    for (int i = 0; i < n; i++) {           // Start of subarray
        int minVal = arr[i];                // Initialize minimum
        int maxVal = arr[i];                // Initialize maximum
        for (int j = i; j < n; j++) {       // End of subarray
            // Update min and max for the current subarray
            minVal = min(minVal, arr[j]);
            maxVal = max(maxVal, arr[j]);

            // Check the condition
            if (maxVal - minVal <= 2) {
                // Print the subarray
                for (int k = i; k <= j; k++) {
                    count++;
                    }
                cout << endl;
            } else {
                break; // Stop expanding this subarray as the condition is violated
            }
        }
    }
    return count;
}
};