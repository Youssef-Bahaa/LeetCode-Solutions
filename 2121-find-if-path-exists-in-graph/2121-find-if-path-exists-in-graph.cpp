class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    bool found = 0 ;
    void dfs(GRAPH& graph , vector<int>& vis , int source , int destination){
        vis[source] = 1;

        if(source == destination){
            found = 1;
            return;
        }

        for(auto i : graph[source]){
            if(!vis[i])dfs(graph , vis , i , destination);
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        GRAPH Graph(n);
        vector<int> vis(n , 0);
        
        for(auto i : edges){
            Graph[i[0]].push_back(i[1]);
            Graph[i[1]].push_back(i[0]);
        }

        dfs(Graph , vis , source , destination);
        return found;
    }
};