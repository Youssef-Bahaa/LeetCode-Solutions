class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       vector<int> idx(nums.size(),1);
       for(int i = 1 ; i < nums.size();i++){
            if(nums[i] > nums[i-1])idx[i] =idx[i-1] + 1;
       }
       for(int i = k -1 ; i < nums.size() - k ; i++){
            if(idx[i] >=k and idx[i + k] >= k)
                return true;
       }
       return false;
    }
};