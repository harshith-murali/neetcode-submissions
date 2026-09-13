class Solution {
public:
    bool topoSort(unordered_map<int, vector<int>>& adj, int numCourses, vector<int>& indegree){
        queue<int> q;
        int count = 0;
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                count++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b -> a
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSort(adj, numCourses, indegree);
    }
};