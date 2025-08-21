class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mini = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            mini = min(mini, nums[mid]);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return mini;
    }
};