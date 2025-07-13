class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> temp = score;
        sort(temp.begin(), temp.end(),greater<>());
        unordered_map<int, int> mp;

        for (int i = 0; i < temp.size(); i++)
            mp[temp[i]] = i + 1;

        for (auto val : score) {
            if (mp[val] == 1)
                ans.push_back("Gold Medal");
            else if (mp[val] == 2)
                ans.push_back("Silver Medal");
            else if (mp[val] == 3)
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(mp[val]));
        }
        return ans;
    }
};