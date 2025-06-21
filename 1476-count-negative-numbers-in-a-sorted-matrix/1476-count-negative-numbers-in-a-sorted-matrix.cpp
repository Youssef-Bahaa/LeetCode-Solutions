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
            while(left <= right){
                int mid = (left + right) / 2;
                if(grid[i][mid] < 0){
                    cnt += grid[i].size() - mid;
                    break;
                }
                else if(grid[i][mid] >= 0)left = mid + 1;
            }

        }

        return cnt;
    }
};