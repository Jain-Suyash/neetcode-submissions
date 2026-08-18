class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
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

        return topo.size() == numCourses;
    }
};
