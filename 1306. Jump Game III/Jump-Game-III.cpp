1class Solution {
2public:
3    vector<int> dp, arr_;
4    int n;
5    bool solve(int idx) {
6        if (idx >= n or idx < 0)
7            return 0;
8        if (arr_[idx] == 0)
9            return 1;
10        if (dp[idx] != -1)
11            return dp[idx];
12
13        dp[idx] = 0; 
14
15        bool left = solve(idx - arr_[idx]);
16        bool right = solve(idx + arr_[idx]);
17
18        return dp[idx] = (left or right);
19    }
20    bool canReach(vector<int>& arr, int start) {
21        n = arr.size();
22        dp.assign(n, -1);
23        arr_ = arr;
24        return solve(start);
25    }
26};