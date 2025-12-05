1class Solution {
2public:
3    int dp[101][101];
4    int cntWays(int r, int c, vector<vector<int>>& v) {
5        if (r >= v.size() or c >= v[0].size() or v[r][c])
6            return 0;
7        if (r == v.size() - 1 and c == v[0].size() - 1)
8            return 1;
9        if (dp[r][c] != -1)
10            return dp[r][c];
11
12        return dp[r][c] = cntWays(r + 1, c, v) + cntWays(r, c + 1, v);
13    }
14    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
15        memset(dp, -1, sizeof(dp));
16        return cntWays(0, 0, obstacleGrid);
17    }
18};