class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH& Graph, int from, int to) {
        Graph[from].push_back(to);
    }

    bool cycle = 0;

    void dfs(GRAPH& Graph, vector<int>& vis, int start) {

        vis[start] = 2;

        for (auto i : Graph[start]) {
            if (!vis[i])
                dfs(Graph, vis, i);

            else if (vis[i] == 2) {
                cycle = 1;
                return;
            }
        }

        vis[start] = 1;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        GRAPH graph(numCourses);
        vector<int> vis(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            add_directed_edge(graph, prerequisites[i][0], prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                dfs(graph, vis, i);
                if (cycle)
                    return 0;
            }
        }
        return 1;
    }
};