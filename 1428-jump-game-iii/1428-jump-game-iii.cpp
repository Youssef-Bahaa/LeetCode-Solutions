class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    void add_directed_edge(GRAPH& graph, int from, int to) {
        graph[from].push_back(to);
    }
    bool valid_move(int sz, int mv) { return mv >= 0 and mv < sz; }

    bool found = 0;

    void dfs(vector<int>& arr, int start, GRAPH& graph, vector<bool>& vis) {
        vis[start] = 1;
        if (arr[start] == 0) {
            found = 1;
            return;
        }
        for (auto neighbour : graph[start]) {
            if (!vis[neighbour])
                dfs(arr, neighbour, graph, vis);
        }
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), 0);
        GRAPH Graph(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            if (valid_move(arr.size(), i - arr[i]))
                add_directed_edge(Graph, i, i - arr[i]);

            if (valid_move(arr.size(), i + arr[i]))
                add_directed_edge(Graph, i, i + arr[i]);
        }

        dfs(arr, start, Graph, vis);
        return found;
    }
};