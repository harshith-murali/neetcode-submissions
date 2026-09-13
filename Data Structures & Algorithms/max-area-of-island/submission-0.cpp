class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i , int j){
        int r = grid.size();
        int c = grid[0].size();
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != 1){
            return 0;
        }
        grid[i][j] = 2;
        return 1 + dfs(grid, i+1, j) + dfs(grid, i, j+1) + dfs(grid , i-1, j) + dfs(grid, i, j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res =0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i , j));
                }
            }
        }
        return res;
    }
};
