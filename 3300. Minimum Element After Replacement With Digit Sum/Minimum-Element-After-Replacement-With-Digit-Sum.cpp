class Solution {
public:
    int sumofdigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for (auto i : nums) {
            mini = min(mini, sumofdigits(i));
        }

        return mini;
    }
};