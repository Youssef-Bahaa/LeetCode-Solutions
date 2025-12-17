1class Solution {
2public:
3    vector<int> prices_;
4    unordered_map<int, unordered_map<bool, unordered_map<int, int>>> dp;
5    // 1 buy
6    // 0 sell
7    int solve(int idx, bool last_trans, int k) {
8        if (!k or idx == prices_.size())
9            return 0;
10        if (dp.count(idx) && dp[idx].count(last_trans) &&
11            dp[idx][last_trans].count(k))
12            return dp[idx][last_trans][k];
13
14        int leave = solve(idx + 1, last_trans, k);
15        int buy = 0;
16        int sell = 0;
17        if (last_trans == 0)
18            buy = -prices_[idx] + solve(idx + 1, 1, k);
19        else
20            sell = prices_[idx] + solve(idx + 1, 0, k - 1);
21
22        return dp[idx][last_trans][k] = max(leave, max(buy, sell));
23    }
24    int maxProfit(vector<int>& prices) {
25        prices_ = prices;
26        return solve(0, 0, 2);
27    }
28};