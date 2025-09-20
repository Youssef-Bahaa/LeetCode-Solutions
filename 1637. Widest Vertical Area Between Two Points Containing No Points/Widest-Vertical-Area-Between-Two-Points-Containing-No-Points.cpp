class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xaxis;
        int maxdis = 0;
        for (auto& i : points)
            xaxis.push_back(i[0]);
        sort(xaxis.begin(), xaxis.end());
        for (int i = 1; i < xaxis.size(); i++)
            maxdis = max(xaxis[i] - xaxis[i - 1], maxdis);
        return maxdis;
    }
};