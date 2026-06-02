class Solution {
public:
bool validCell(int r, int c, int n, int m){
    return r >= 0 && r < n && c >= 0 && c < m;
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int,int>,int>> q;

    int cntFresh = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else if(grid[i][j]==1){
                cntFresh++;
                vis[i][j]=0;
            }
        }
    }

    int tm = 0;
    int cnt = 0;

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int r = it.first.first;
        int c = it.first.second;
        int t = it.second;

        tm = max(tm, t);

        for(int i=0;i<4;i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(validCell(nr,nc,n,m) && grid[nr][nc]==1 && vis[nr][nc]!=2){
                q.push({{nr,nc}, t+1});
                vis[nr][nc]=2;
                cnt++;
            }
        }
    }

    if(cnt != cntFresh) return -1;
    return tm;
}
};