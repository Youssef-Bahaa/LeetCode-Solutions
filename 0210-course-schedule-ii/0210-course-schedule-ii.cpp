class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    void add_directed(GRAPH& graph , int from , int to){
        graph[from].push_back(to);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> ordered;

        if(prerequisites.empty()){
            for(int i = 0 ; i < numCourses;i++)ordered.push_back(i);

            return ordered;
        }

        GRAPH Graph(numCourses);
        for(auto i : prerequisites)
            add_directed(Graph , i[1] , i[0]);

        vector<int> indegree(Graph.size(), 0);

        for(auto i : Graph){
            for(auto j : i)indegree[j]++;
        }

        queue<int> q;

        for(int i = 0 ; i < numCourses; i++)if(!indegree[i])q.push(i);


        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ordered.push_back(temp);
            for(auto i : Graph[temp]){
                if(--indegree[i] == 0)
                    q.push(i);
            }
        }
        if(ordered.size() != numCourses)return {};
        return ordered;
    }
};