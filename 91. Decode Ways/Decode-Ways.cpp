1class Solution {
2public:
3    int dp[101];
4    int solve(int idx, string& s) {
5        if (idx == s.size())
6            return 1;
7        if (s[idx] == '0')
8            return 0;
9        if (dp[idx] != -1)
10            return dp[idx];
11
12        int ways = solve(idx + 1, s);
13        if (cantake2(idx, s))
14            ways += solve(idx + 2, s);
15
16        return dp[idx] = ways;
17    }
18    bool cantake2(int idx, string& s) {
19        if (idx + 1 == s.size())
20            return false;
21        int num = stoi(s.substr(idx, 2));
22        return num >= 1 and num <= 26;
23    }
24
25    int numDecodings(string s) { 
26        memset(dp, -1, sizeof(dp)); 
27        return solve(0,s);
28    }
29};