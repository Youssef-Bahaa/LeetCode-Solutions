class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    vector<vector<int>> path;
    vector<int> currentPath; 
    void dfs(GRAPH& graph , int start){
        currentPath.push_back(start);
        if(start == graph.size() - 1){
            path.push_back(currentPath);
        }
        else{
            for(auto i : graph[start])
                dfs(graph , i);
            
        }
       currentPath.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        GRAPH Graph(n);
        for(int i = 0 ; i < n; i++)
            for(int j = 0 ; j < graph[i].size(); j++)Graph[i].push_back(graph[i][j]);
        
        dfs(Graph , 0);
        return path;
    }
};