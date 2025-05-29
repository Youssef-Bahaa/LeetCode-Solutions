class Solution {
public:
    int dp[2501][2501];
    
    int solve(int idx , int last_idx , vector<int>& nums ){
        if(idx == nums.size())return 0;

        if(dp[idx][last_idx] !=-1)
            return dp[idx][last_idx ];

        int leave = solve(idx + 1 , last_idx , nums);
        int take = 0;
        if(last_idx >= nums.size() or nums[last_idx] < nums[idx])
             take = 1 + solve(idx + 1 , idx , nums);

        return dp[idx][last_idx ] = max(take, leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , nums.size() , nums);
    }
}; 