class Solution {
public:
    typedef vector<vector<int>> GRAPH;

    int dfs(GRAPH& graph, vector<bool>& hasApple, int cur,int parent) {
        int ans = 0 ;

        for(auto i : graph[cur]){
            if(i==parent)continue;
            ans += dfs(graph , hasApple , i , cur);
        }
        if( ans > 0 or hasApple[cur])
            ans += 2;

        return ans;
    }


    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        GRAPH Graph(n);

        for (auto i : edges) {
            Graph[i[0]].push_back(i[1]);
            Graph[i[1]].push_back(i[0]);
        }

        int ans =  dfs(Graph, hasApple, 0, -1);
        if(ans)return ans - 2;
        return 0 ;
    }
};