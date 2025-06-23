class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, vis, mat, delrow, delcol);
            }
            if (mat[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' && !vis[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
