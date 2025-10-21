class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right ) / 2;
            mini = min(mini,nums[mid]);
            if(nums[right] < nums[mid])left = mid + 1;
            else right = mid - 1;
        }
        return mini;
    }
};