1class Solution {
2public:
3    int dp[1001];
4    int solve(int target, vector<int>& nums) {
5        if (target < 0)
6            return 0;
7        if (target == 0)
8            return 1;
9            
10        if (dp[target] != -1)
11            return dp[target];
12
13        int cnt = 0;
14        for(auto& c : nums)
15            cnt += solve(target - c,nums);
16            
17        return dp[target] = cnt;
18    }
19    int combinationSum4(vector<int>& nums, int target) {
20        memset(dp, -1, sizeof(dp));
21        return solve(target, nums);
22    }
23};