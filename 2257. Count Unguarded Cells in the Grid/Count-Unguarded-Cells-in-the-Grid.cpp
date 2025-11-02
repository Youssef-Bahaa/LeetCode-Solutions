class Solution {
public:
    bool notvalid(char val) { return val == 'G' or val == 'W'; }

    void make_gaurded(vector<vector<char>>& arr, int i, int j) {
        // go left
        for (int col = j - 1; col >= 0; col--) {
            if (notvalid(arr[i][col]))
                break;
            arr[i][col] = 'R';
        }
        // go right
        for (int col = j + 1; col < arr[0].size(); col++) {
            if (notvalid(arr[i][col]))
                break;
            arr[i][col] = 'R';
        }
        // go top
        for (int row = i - 1; row >= 0; row--) {
            if (notvalid(arr[row][j]))
                break;
            arr[row][j] = 'R';
        }
        // go down
        for (int row = i + 1; row < arr.size(); row++) {
            if (notvalid(arr[row][j]))
                break;
            arr[row][j] = 'R';
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        int cnt = 0;
        vector<vector<char>> arr(m, vector<char>(n, 'g'));
        for (auto& i : guards)
            arr[i[0]][i[1]] = 'G';
        for (auto& i : walls)
            arr[i[0]][i[1]] = 'W';

        for (auto n : guards)
            make_gaurded(arr, n[0], n[1]);

        for (auto i : arr) {
            for (auto j : i)
                cnt += j == 'g';
        }

        return cnt;
    }
};