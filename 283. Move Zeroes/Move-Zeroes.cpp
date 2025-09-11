class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        while (r != nums.size() and l != nums.size()) {
            if (nums[l] == 0) {
                if (nums[r] != 0)
                    swap(nums[l++], nums[r]);
                r++;
            }
            
            else
                l++, r++;
        }
    }
};