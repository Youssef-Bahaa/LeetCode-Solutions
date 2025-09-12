class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++)
            mp[groupSizes[i]].push_back(i);

        for (auto i : mp) {
            int val = i.first;
            int sz = i.second.size();
            vector<int> temp;
            for (int j = 0; j < sz; j++) {
                if (j != 0 and j % val == 0) {
                    ans.push_back(temp);
                    temp.clear();
                }
                temp.push_back(i.second[j]);
            }
            if (!temp.empty())
                ans.push_back(temp);
        }

        return ans;
    }
};