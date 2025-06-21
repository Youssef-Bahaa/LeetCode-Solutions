class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = m - 1;

        while(j >=0 and i< n){
            int num = grid[i][j];
            if(num < 0){
                cnt += n - i;
                j--;
            }
            else
                i++;
        }

        return cnt;
    }
};