class Solution {
   public:
    bool isValid(int r, int c, int n, int m) { return r >= 0 && r < n && c >= 0 && c < m; }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }else if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int tm = 0;
        int cntRotted = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc, n , m) && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, t+1});
                    cntRotted++;
                }
            }
        }

        return (cntFresh == cntRotted) ? tm : -1;
    }
};
