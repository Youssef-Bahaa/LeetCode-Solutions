class Solution {
public:
    int rev(int n) {
        int res = 0;
        int l = 1;
        while (n) {
            res = res * l + n % 10;
            n /= 10;
            l = 10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(rev(nums[i]));
        }
        unordered_set<int> st;
        for (auto i : nums)
            st.insert(i);
        return st.size();
    }
};