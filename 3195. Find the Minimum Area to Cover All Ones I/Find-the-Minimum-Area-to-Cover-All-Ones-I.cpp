class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow = INT_MAX,mincol = INT_MAX,maxrow = 0,maxcol = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    minrow = min(minrow, i);
                    mincol = min(mincol, j);
                    maxcol = max(maxcol, j);
                    maxrow = i;
                }
            }
        }
        return (maxcol - mincol + 1) * (maxrow - minrow + 1);
    }
};