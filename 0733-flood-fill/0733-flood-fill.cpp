class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();    
        int n = image[0].size();  

        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        vector<vector<int>> ans = image; 

        queue<pair<int, int>> q;
        int oriColor = image[sr][sc]; 

        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                   vis[nrow][ncol] == 0 && image[nrow][ncol] == oriColor) {
                    
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = color; 
                }
            }
        }

        return ans;
    }
};