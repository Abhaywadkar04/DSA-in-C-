class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return helper(m - 1, n - 1, memo);
    }

private:
    int helper(int row, int col, vector<vector<int>>& memo) {
        if (row == 0 && col == 0) return 1;
        
        if (row < 0 || col < 0) return 0;
        
        if (memo[row][col] != -1) return memo[row][col];
        
        int up = helper(row - 1, col, memo);
        int left = helper(row, col - 1, memo);
        
        return memo[row][col] = up + left;
    }
};
