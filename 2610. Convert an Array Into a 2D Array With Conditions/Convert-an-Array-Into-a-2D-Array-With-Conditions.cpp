class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        for (auto i : nums) {
            mp[i]++;
        }
        for (auto i : mp)
            maxi = max(maxi, i.second);

        vector<vector<int>> ans(maxi);

        for (int i = 0; i < maxi; i++) {
            for (auto j : mp) {
                if (j.second) {
                    ans[i].push_back(j.first);
                    mp[j.first]--;
                }
            }
        }

        return ans;
    }
};