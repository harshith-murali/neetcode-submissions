class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<vector<int>> q; // {stops, node, distance}
        q.push({0, src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int stops = curr[0];
            int node = curr[1];
            int d = curr[2];

            if (stops > k)
                continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edWt = it.second;

                if (d + edWt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = d + edWt;
                    q.push({stops + 1, adjNode, dist[adjNode]});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};