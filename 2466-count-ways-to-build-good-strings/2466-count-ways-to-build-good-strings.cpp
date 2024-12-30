class Solution {
public:
    int l;
    int h;
    int z;
    int o;
    const int m = 1e9 + 7;

    int solve(int L, vector<int>& t) {     
        if (L > h) {
            return 0;
        }
        if (t[L] != -1) return t[L];

        bool signal = (L >= l);
        int append_zero = solve(L + z, t);
        int append_one = solve(L + o, t);

        return t[L] = (signal + append_zero + append_one) % m;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        l = low;
        h = high;
        z = zero;
        o = one;

        // Initialize memoization vector
        vector<int> t(h + 1, -1);
        return solve(0, t);
    }
};
