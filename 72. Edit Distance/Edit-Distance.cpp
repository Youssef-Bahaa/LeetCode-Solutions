1class Solution {
2public:
3    int dp[501][501];
4    int solve(int i, int j, string& word1, string& word2) {
5        if (i == word1.size())
6            return word2.size() - j;
7        if (j == word2.size())
8            return word1.size() - i;
9
10        if (dp[i][j] != -1)
11            return dp[i][j];
12
13        if (word1[i] == word2[j])
14            return solve(i + 1, j + 1, word1, word2);
15
16        int change = 1 + solve(i + 1, j + 1, word1, word2);
17        int insert = 1 + solve(i, j + 1, word1, word2);
18        int delete_ = 1 + solve(i + 1, j, word1, word2);
19
20        return dp[i][j] = min(min(insert, delete_), change);
21    }
22    int minDistance(string word1, string word2) {
23        memset(dp, -1, sizeof(dp));
24        return solve(0, 0, word1, word2);
25    }
26};