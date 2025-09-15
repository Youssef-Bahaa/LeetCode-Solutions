class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini = INT_MAX ;
        for(auto& i : tasks)
            mini = min(mini,i[0] + i[1]);
        
        return mini;
    }
};