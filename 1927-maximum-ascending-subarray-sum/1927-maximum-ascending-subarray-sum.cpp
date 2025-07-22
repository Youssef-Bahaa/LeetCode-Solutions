class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0 , maxi = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            if(i and nums[i] <= nums[i - 1]){
                maxi = max(maxi,sum);
                sum = 0 ;
            }
            sum += nums[i];
        }
        return max(maxi,sum);
    }
};