class Solution {
public:
    int f(int r , int c , vector<vector<int>>& grid , vector<vector<int>>& dp ){
        if(r == 0 && c == 0) return grid[0][0];

        if(dp[r][c] != -1) return dp[r][c];

        int up = INT_MAX, left = INT_MAX;

        if(r > 0)
            up = grid[r][c] + f(r-1, c, grid, dp);

        if(c > 0)
            left = grid[r][c] + f(r, c-1, grid, dp);

        return dp[r][c] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int> (n, -1));
        return f(m-1, n-1, grid, dp);
    }
};