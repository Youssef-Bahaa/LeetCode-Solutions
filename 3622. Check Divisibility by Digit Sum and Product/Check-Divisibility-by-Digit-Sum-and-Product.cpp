class Solution {
public:
    int digsum_plus_multiply(int num) {
        int sum = 0;
        int res = 1;
        while (num) {
            sum += num % 10;
            res *= num % 10;
            num /= 10;
        }
        return sum + res;
    }
    bool checkDivisibility(int n) {
        return n % (digsum_plus_multiply(n)) == 0;
    }
};