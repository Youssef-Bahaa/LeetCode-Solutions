class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for (auto i : nums)
            maxi = max(maxi, ++mp[i]);

        vector<vector<int>> ans(maxi);

        for (int i = 0; i < maxi; i++) {
            for (auto& j : mp) {
                if (j.second) {
                    ans[i].push_back(j.first);
                    j.second--;
                }
            }
        }

        return ans;
    }
};