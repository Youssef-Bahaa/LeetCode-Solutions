1class Solution {
2public:
3    int dp[101][101];
4    int cntWays(int r, int c, int m, int n) {
5        if (r == m - 1 and c == n - 1)
6            return 1;
7        if (r >= m or c >= n)
8            return 0;
9
10        if (dp[r][c] != -1)
11            return dp[r][c];
12
13        return dp[r][c] = cntWays(r + 1, c, m, n) + cntWays(r, c + 1, m, n);
14    }
15    int uniquePaths(int m, int n) {
16        memset(dp, -1, sizeof(dp));
17        return cntWays(0, 0, m, n);
18    }
19};