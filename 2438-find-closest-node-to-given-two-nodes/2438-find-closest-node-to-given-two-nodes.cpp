class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    void dfs(GRAPH& graph, vector<int>& dis, int start) {

        for (auto i : graph[start]) {
            if (dis[i] == -1) {
                dis[i] = dis[start] + 1;
                dfs(graph, dis, i);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, -1), dis2(n, -1);
        GRAPH Graph(n);
        dis1[node1] = 0;
        dis2[node2] = 0;

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                Graph[i].push_back(edges[i]);
        }

        dfs(Graph, dis1, node1);
        dfs(Graph, dis2, node2);

        int mindis = INT_MAX;
        int node = -1;

        for (int i = 0; i < n; i++) {
            if (dis1[i] != -1 and dis2[i] != -1) {
                int maxi = max(dis1[i], dis2[i]);
                if (maxi < mindis) {
                    mindis = maxi;
                    node = i;
                }
            }
        }

        return node;
    }
};