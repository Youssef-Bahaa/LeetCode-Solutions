class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[max1])
                max1 = i;
        }
        int val = nums[max1];
        nums[max1] = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[max2])
                max2 = i;
        }

        return (val - 1) * (nums[max2] - 1);
    }
};