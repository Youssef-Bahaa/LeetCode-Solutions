1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int l = 0, r = nums.size() - 1;
5        if(!r)return 0;
6        while (l <= r) {
7            int mid = (l + r) / 2;
8            if (mid == 0 and nums[mid] > nums[mid + 1])
9                return mid;
10            if (mid == nums.size() - 1 and nums[mid] > nums[mid - 1])
11                return mid;
12            if (mid and nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
13                return mid;
14            else if (mid and nums[mid] < nums[mid - 1])
15                r = mid - 1;
16            else if (nums[mid] < nums[mid + 1])
17                l = mid + 1;
18        }
19        return -1;
20    }
21};