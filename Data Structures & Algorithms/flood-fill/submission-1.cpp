class Solution {
   public:
   bool isValidCell(int currRow ,int currCol , int m , int n){
    return currRow >= 0 && currRow < m && currCol >= 0 && currCol < n;
   }
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor,
             int delRow[], int delCol[], int iniColor) {
        int m = image.size();
        int n = image[0].size();
        ans[sr][sc] = newColor;
        for(int i=0; i<4; i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if(isValidCell(nrow , ncol , m , n) && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                dfs(nrow , ncol , ans ,image , newColor , delRow , delCol , iniColor);
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        if (iniColor == newColor) {
            return ans;
        }
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        return ans;
    }
};