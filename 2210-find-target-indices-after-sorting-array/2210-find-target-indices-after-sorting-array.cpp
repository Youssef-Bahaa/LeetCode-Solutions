class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> idx;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == target)idx.push_back(i);
        }
        return idx;
    }
};