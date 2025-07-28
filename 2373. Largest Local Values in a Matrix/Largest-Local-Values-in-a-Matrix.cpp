class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() - 2;
        vector<vector<int>> ans(n, vector<int>(n));

        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                int maxi = INT_MIN;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        maxi = max(maxi, grid[i][j]);
                    }
                }
                ans[row][col] = maxi;
            }
        }

        return ans;
    }
};