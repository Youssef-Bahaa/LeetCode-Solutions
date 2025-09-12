class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bot = matrix.size() - 1;
        int l = 0, r = matrix[0].size() - 1;

        while (top <= bot and l <= r) {
            // left to right
            for (int j = l; j <= r; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // top to bottom
            for (int j = top; j <= bot; j++) {
                ans.push_back(matrix[j][r]);
            }
            r--;

            // right to left
            if (top <= bot) {
                for (int j = r; j >= l; j--) {
                    ans.push_back(matrix[bot][j]);
                }
                bot--;
            }

            if (l <= r) {
                for (int j = bot; j >= top; j--) {
                    ans.push_back(matrix[j][l]);
                }

                l++;
            }
        }

        return ans;
    }
};