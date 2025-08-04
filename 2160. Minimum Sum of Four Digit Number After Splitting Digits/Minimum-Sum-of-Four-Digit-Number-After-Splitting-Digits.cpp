class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string num1 = string(1, s[0]) + string(1, s[3]);
        string num2 = string(1, s[1]) + string(1, s[2]);
        return stoi(num1) + stoi(num2);
    }
};