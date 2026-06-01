class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjLs){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it , vis , adjLs);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> adjLs(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && adj[i][j] == 1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i , vis , adjLs);
            }
        }
        return cnt;
    }
};