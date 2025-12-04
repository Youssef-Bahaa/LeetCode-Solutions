1class Solution {
2public:
3    int dp[1001];
4    int solve(int idx, vector<int>& cost) {
5        if (idx >= cost.size())
6            return 0;
7        if (dp[idx] != -1)
8            return dp[idx];
9
10        int pick1 = cost[idx] + solve(idx + 1, cost);
11        int pick2 = cost[idx] + solve(idx + 2, cost);
12
13        return dp[idx] = min(pick1, pick2);
14    }
15    int minCostClimbingStairs(vector<int>& cost) {
16        memset(dp, -1, sizeof(dp));
17        return min(solve(0, cost), solve(1, cost));
18    }
19};