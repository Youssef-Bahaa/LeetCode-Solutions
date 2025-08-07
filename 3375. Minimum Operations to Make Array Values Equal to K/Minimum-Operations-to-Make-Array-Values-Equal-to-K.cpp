class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set <int> ans;
        for(auto i : nums){
            if(i > k)ans.insert(i);
            else if(i < k )return -1;
        }
        return ans.size();
    }
};