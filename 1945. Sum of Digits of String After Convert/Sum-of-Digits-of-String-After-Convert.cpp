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
    int getLucky(string s, int k) {
        string str = "";
        int num = 0;
        for (auto i : s) {
            str += to_string((i - 'a') + 1);
        }
        for (auto c : str)
            num += (c - '0');

        k--;
        while (k--) {
            num = sumofdigits(num);
        }

        return num;
    }
};