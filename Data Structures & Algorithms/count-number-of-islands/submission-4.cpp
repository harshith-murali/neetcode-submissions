class Solution {
   public:
    bool isValid(int r, int c, int n, int m) { return r >= 0 && r < n && c >= 0 && c < m; }

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = i + delrow[k];
            int nc = j + delcol[k];
            if (isValid(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == '1') {
                dfs(nr, nc, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};
