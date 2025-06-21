class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;

        for(int i = 0 ; i < grid.size(); i++){
            if(grid[i][0] < 0 ){
                cnt += grid[i].size();
                continue;
            }

            int left = 0 , right =grid[i].size() - 1;
            int first_nega = -1;

            while(left <= right){
                int mid = (left + right) / 2;
                if(grid[i][mid] < 0){
                    first_nega = mid ;
                    right = mid - 1;

                }
                else if(grid[i][mid] >= 0)left = mid + 1;
            }
            if(first_nega != -1)
                cnt += grid[i].size() - first_nega;

        }

        return cnt;
    }
};