class Solution {
    vector<vector<int>> adj;
    vector<int> indegree;
    vector<bool> vis;

    bool bfs(int n) {
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(!indegree[i]) {
                q.push(i);
                vis[i] = true;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans++;
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    indegree[v]--;

                    if (!indegree[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return ans == n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int sz = prerequisites.size();

        adj.assign(n, {});
        indegree.assign(n, 0);
        vis.assign(n, false);

        for (int i = 0; i < sz; i++) {
            auto vec = prerequisites[i];
            for (int j = 0; j < 2; j++) {
                adj[vec[0]].push_back(vec[1]);
                indegree[vec[1]]++;
            }
        }
        
        return bfs(n);
    }
};