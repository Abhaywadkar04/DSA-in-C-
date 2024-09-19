class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == divisor) return 1;
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = true;
        long ans = 0;
        
        if (divisor < 0 && dividend >= 0) sign = false;
        if (divisor > 0 && dividend <= 0) sign = false;

        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        while (absDividend >= absDivisor) {
            int count = 0;
            
            while (absDividend >= (absDivisor << (count + 1))) {
                count++;
            }

            ans += (1 << count);
            absDividend -= (absDivisor << count);
        }

        if (ans >= (1LL << 31) && sign == true) return INT_MAX;
        if (ans >= (1LL << 31) && sign == false) return INT_MIN;

        return sign ? ans : (-1 * ans);
    }
};
