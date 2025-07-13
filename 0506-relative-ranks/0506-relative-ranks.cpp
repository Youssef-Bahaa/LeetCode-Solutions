class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int, int>> score_idx;

        for (int i = 0; i < n; i++)
            score_idx.push_back({score[i], i });

        sort(score_idx.begin(), score_idx.end(), greater<>());

        for (int i = 0; i < score.size(); i++) {
            int idx = score_idx[i].second;
            if (i == 0)
                ans[idx] = "Gold Medal";
            else if (i == 1)
                ans[idx] = "Silver Medal";
            else if (i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }
        return ans;
    }
};