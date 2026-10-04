class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    void islandsAndTreasure(vector<vector<int>>& adj) {
        int n = adj.size();
        int m = adj[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue < pair < pair<int, int>, int >> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            adj[r][c] = steps;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (isValid(nr, nc, n, m) && !vis[nr][nc] && adj[nr][nc] == 2147483647) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, steps + 1});
                }
            }
        }
    }
};
