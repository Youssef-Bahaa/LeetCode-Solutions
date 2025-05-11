class Solution {
public:
    typedef unordered_map <int ,vector<int> > GRAPH;
    void add_undirected_graph(GRAPH& graph , int from , int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void dfs(GRAPH& graph , int node , unordered_set<int>& vistied , vector<int>& ans){
        vistied.insert(node);
        ans.push_back(node);
        for(auto neighbour : graph[node]){
            if(!vistied.count(neighbour))
                dfs(graph , neighbour , vistied , ans);
        }

    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        GRAPH graph;
        vector<int> ans;
        unordered_set<int> vistied;
        for(auto &i : adjacentPairs)
            add_undirected_graph(graph , i[0] , i[1]);
        
        for(auto &i : graph){
            if(i.second.size() == 1){
                dfs(graph , i.first , vistied , ans);
                break;}
        }
        return ans;
    }
};