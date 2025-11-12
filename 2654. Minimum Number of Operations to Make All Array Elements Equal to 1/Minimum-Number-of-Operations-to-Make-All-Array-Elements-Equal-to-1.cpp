class Solution {
public:
    int minOperations(vector<int>& nums) {
        int one_count = 0;
        for (auto i : nums)
            one_count += i == 1;
        if (one_count)
            return nums.size() - one_count;

        int min_sub_len = INT_MAX;
        for (int l = 0; l < nums.size(); l++) {
            int cur_gcd = 0;
            for (int r = l; r < nums.size(); r++) {
                cur_gcd = gcd(cur_gcd, nums[r]);
                if (cur_gcd == 1) {
                    min_sub_len = min(r - l + 1,min_sub_len);
                    break;
                }
            }
        }
        if (min_sub_len == INT_MAX)
            return -1;

    return (min_sub_len - 1) + (nums.size() - 1);   
    }
};