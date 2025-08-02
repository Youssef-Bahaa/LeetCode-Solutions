class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n);
        vector<int> rightsum(n);
        vector<int> ans;

        int lsum = 0, rsum = 0;
        for (int i = 0; i < n; i++) {
            leftsum[i] = lsum;
            lsum += nums[i];

            rightsum[n - i - 1] = rsum;
            rsum += nums[n - i - 1];
        }

        for (int i = 0; i < n; i++) {
            ans.push_back(abs(leftsum[i] - rightsum[i]));
        }
        return ans;
    }
};