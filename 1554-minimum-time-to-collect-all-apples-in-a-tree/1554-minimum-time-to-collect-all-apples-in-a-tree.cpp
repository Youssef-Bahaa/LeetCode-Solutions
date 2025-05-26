class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    int time = 0;

    bool routehasapples(GRAPH& graph, vector<bool>& vis, int start,vector<bool>& hasApple) {


        if (hasApple[start])
            return true;

        vis[start] = 1;

        for (auto i : graph[start]) {
            if (!vis[i] and routehasapples(graph, vis, i, hasApple))
                return true;
        }

        return false;
    }
    void dfs(GRAPH& graph, vector<bool>& hasApple, int start,vector<bool>& vis) {
        vis[start] = 1;
        for (auto neighbour : graph[start])
            if (!vis[neighbour]) {
                vector<bool> tempvis(vis);
                if (routehasapples(graph, tempvis, neighbour, hasApple)) {
                    time += 2;
                    dfs(graph, hasApple, neighbour, vis);
                }
            }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        GRAPH Graph(n);
        vector<bool> vis(n, 0);

        for (auto i : edges) {
            Graph[i[0]].push_back(i[1]);
            Graph[i[1]].push_back(i[0]);
        }

        dfs(Graph, hasApple, 0, vis);

        return time;
    }
};