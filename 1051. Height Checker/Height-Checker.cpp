class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt = 0;
        vector<int> exheights = heights;
        sort(exheights.begin(), exheights.end());
        for (int i = 0; i < heights.size(); i++)
            if (exheights[i] != heights[i])
                cnt++;
        return cnt;
    }
};