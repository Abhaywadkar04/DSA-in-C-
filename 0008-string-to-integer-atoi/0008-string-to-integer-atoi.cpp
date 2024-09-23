class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        bool sign = true;  // true for positive, false for negative

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = false;  
            }
            i++;  
        }

        // Build the number from numeric characters
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Handle overflow and underflow
            if (sign && result > INT_MAX) {
                return INT_MAX;
            } else if (!sign && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        if (!sign) {
            result = -result;
        }

        return (int)result;
    }
};
