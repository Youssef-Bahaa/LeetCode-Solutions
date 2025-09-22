class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans = 0 ;
        for(auto i : nums){
            if(s.count(i + diff) and s.count(i + 2 * diff))ans++;
        }
        return ans;
    }
};