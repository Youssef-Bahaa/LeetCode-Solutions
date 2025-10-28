class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0 , left = 0 , right = 0,sum=0;
        for(int v : nums)sum += v;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                right = sum - left;
                int diff = abs(right-left);
                if(diff == 0) ans += 2;
                else if(diff == 1) ans += 1; 
            }
            left += nums[i];
        }
        return ans;
    }
};