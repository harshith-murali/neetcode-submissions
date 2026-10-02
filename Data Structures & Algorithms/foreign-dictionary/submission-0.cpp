class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        // Mark characters that actually exist
        for (string word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    indegree[s2[ptr] - 'a']++;
                    found = true;
                    break;
                }
            }

            // Invalid ordering: longer word comes before its prefix
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Topological sort
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo += char(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Cycle detected
        int totalChars = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalChars++;
            }
        }

        if (topo.size() != totalChars) {
            return "";
        }

        return topo;
    }
};