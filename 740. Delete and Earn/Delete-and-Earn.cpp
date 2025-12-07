1class Solution {
2public:
3    vector<int> dp;
4    vector<int> arr;
5    int solve(int idx) {
6        if (idx >= arr.size())
7            return 0;
8        if (dp[idx] != -1)return dp[idx];
9        
10        int leave = solve(idx + 1);
11        int pick = arr[idx] + solve(idx + 2);
12        return dp[idx] = max(pick, leave);
13    }
14    int deleteAndEarn(vector<int>& nums) {
15        dp.assign(10001, -1);
16        arr.assign(10001, 0);
17        for (auto& i : nums)arr[i] += i;
18        return solve(0);
19    }
20};