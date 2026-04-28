class Solution {
public:
    int f(int r , int c , vector<vector<int>> & dp,vector<vector<int>>& obstacleGrid){
        if(r < 0 || c < 0){
            return 0;
        }
        if(dp[r][c] != -1) return dp[r][c];
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;
        int up = f(r-1 , c, dp,obstacleGrid);
        int left = f(r,c-1,dp,obstacleGrid);
        return dp[r][c] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m , vector<int> (n , -1));
        return f(m-1, n-1,dp,obstacleGrid);
    }
};