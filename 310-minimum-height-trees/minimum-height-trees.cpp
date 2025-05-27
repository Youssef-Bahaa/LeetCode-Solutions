class Solution {
public:
    typedef vector<vector<int>> GRAPH;


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)return{0};
        
        GRAPH Graph(n);
        vector<int> ans;
        vector<int> indegree(n,0);
        
        for (auto i : edges) {
            Graph[i[0]].push_back(i[1]);
            Graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i = 0 ; i < indegree.size(); i++)if(indegree[i] ==1 )q.push(i);

        int sz = n;

        while(sz > 2){
            int levelsz = q.size();
            sz -= levelsz;
            while(levelsz--){
                int temp = q.front();
                q.pop();
                for(auto i : Graph[temp]){
                    if(--indegree[i] == 1)q.push(i);
                }
            }

        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};