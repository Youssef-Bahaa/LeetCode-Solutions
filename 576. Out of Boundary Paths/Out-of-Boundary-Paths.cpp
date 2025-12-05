1class Solution {
2public:
3    int dp[51][51][51];
4    int rows, cols, maxMove;
5    int MOD = 1e9 + 7;
6
7    int ways(int r, int c, int moves) {
8        if (moves > maxMove)
9            return 0;
10        if (r >= rows or r < 0 or c >= cols or c < 0)
11            return 1;
12
13        if (dp[r][c][moves] != -1)
14            return dp[r][c][moves];
15
16        int way = ways(r + 1, c, moves + 1);
17        way %= MOD;
18
19        way += ways(r, c + 1, moves + 1);
20        way %= MOD;
21
22        way += ways(r - 1, c, moves + 1);
23        way %= MOD;
24
25        way += ways(r, c - 1, moves + 1);
26        way %= MOD;
27        return dp[r][c][moves] = way;
28    }
29    int findPaths(int m, int n, int maxMoves, int startRow, int startColumn) {
30        memset(dp, -1, sizeof(dp));
31        rows = m;
32        cols = n;
33        maxMove = maxMoves;
34
35        return ways(startRow, startColumn, 0);
36    }
37};