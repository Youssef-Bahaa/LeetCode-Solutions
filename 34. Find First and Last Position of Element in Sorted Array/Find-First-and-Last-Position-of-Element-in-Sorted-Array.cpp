class Solution {
public:
    int first(vector<int>& nums, int val) {
        int st = 0, end = (int)nums.size() - 1, mid, pos = -1;
        while (st <= end) {
            mid = (st + end) / 2;
            if (val > nums[mid])
                st = mid + 1;
            else if (val < nums[mid])
                end = mid - 1;
            else
                pos = mid, end = mid - 1;
        }
        return pos;
    }
    int last(vector<int>& nums, int val) {
        int st = 0, end = (int)nums.size() - 1, mid, pos = -1;
        while (st <= end) {
            mid = (st + end) / 2;
            if (val > nums[mid])
                st = mid + 1;
            else if (val < nums[mid])
                end = mid - 1;
            else
                pos = mid, st = mid + 1;
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target), last(nums, target)};
    }
};