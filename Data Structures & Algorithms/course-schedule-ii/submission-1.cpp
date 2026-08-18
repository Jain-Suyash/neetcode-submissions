class Solution {
   public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                inDegree[adj[node][i]]--;
                if (inDegree[adj[node][i]] == 0) q.push(adj[node][i]);
            }
        }

        if (topo.size() == V) return topo;
        return {};
    }
};
