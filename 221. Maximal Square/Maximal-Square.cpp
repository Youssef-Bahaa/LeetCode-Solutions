1class Solution {
2public:
3    int dp[301][301];
4    int solve(int r, int c, vector<vector<char>>& matrix) {
5        if (r < 0 or c < 0 or matrix[r][c] == '0')
6            return 0;
7        if (dp[r][c] != -1)
8            return dp[r][c];
9
10        int up = solve(r - 1, c, matrix);
11        int dig = solve(r - 1, c - 1, matrix);
12        int left = solve(r, c - 1, matrix);
13
14        return dp[r][c] = 1 + min(dig, min(up, left));
15    }
16    int maximalSquare(vector<vector<char>>& matrix) {
17        int side = INT_MIN;
18        memset(dp, -1, sizeof(dp));
19        for (int i = 0; i < matrix.size(); i++)
20            for (int j = 0; j < matrix[0].size(); j++)
21                side = max(side, solve(i, j, matrix));
22
23        return side * side;
24    }
25};