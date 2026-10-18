class Solution {
public:
    int f(int i, int j, int m , int n , vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(i==0 && j == 0 ) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,m,n,dp);
        int left = f(i,j-1,m,n,dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,m,n,dp);
    }
};
