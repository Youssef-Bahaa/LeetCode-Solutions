class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> st;
        vector<int> ans;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++)
                count += mat[i][j];
            st.push_back({count, i});
        }
        sort(st.begin(), st.end());

        for (int i = 0; i < k; i++)
            ans.push_back(st[i].second);

        return ans;
    }
};