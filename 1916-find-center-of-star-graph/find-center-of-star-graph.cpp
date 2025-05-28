class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    int stnode = -1;
    void dfs(GRAPH& graph , vector<bool>& vis ,vector<vector<int>>& edges , int start){
        vis[start] = 1 ;
        
        if(graph[start].size() == edges.size()){
            stnode = start;
            return ; 
        }

        for(auto i : graph[start]){
            if(!vis[i])dfs(graph , vis , edges,  i);
        }
    }

    int findCenter(vector<vector<int>>& edges) {
        GRAPH Graph(edges.size() + 2);
        vector<bool> vis(edges.size() + 2 , 0);

        for(auto i : edges){
            Graph[i[0]].push_back(i[1]);
            Graph[i[1]].push_back(i[0]);
        }

        dfs(Graph , vis , edges,edges[0][0]);
        
        return stnode;
        
    }
};