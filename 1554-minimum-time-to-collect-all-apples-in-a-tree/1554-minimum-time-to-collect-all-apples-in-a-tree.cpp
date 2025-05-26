class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    int time = 0;

    bool routehasapples(GRAPH& graph, int parent, int start,vector<bool>& hasApple) {
        if (hasApple[start])
            return true;

        for (auto i : graph[start]) {
            if (i == parent)
                continue;
            if (routehasapples(graph, start, i, hasApple))
                return true;
        }

        return false;
    }
    void dfs(GRAPH& graph, vector<bool>& hasApple, int start,int parent) {
        for (auto neighbour : graph[start]) {

            if (neighbour == parent)
                continue;

            if (routehasapples(graph, start, neighbour, hasApple)) {
                time += 2;
                dfs(graph, hasApple, neighbour, start);
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

        dfs(Graph, hasApple, 0, -1);

        return time;
    }
};