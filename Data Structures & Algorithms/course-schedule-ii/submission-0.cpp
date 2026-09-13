class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, int numCourses, vector<int>& indegree){
        queue<int> q;
        vector<int> result;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return (result.size() == numCourses) ? result : vector<int>();
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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