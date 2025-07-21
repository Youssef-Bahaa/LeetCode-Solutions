class Solution {
public:
    string makeFancyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i + 1] and s[i + 1] == s[i + 2])
                s[i] = '.';
        }
        string res = "";
        for (auto i : s) {
            if (i != '.')
                res += i;
        }
        return res;
    }
};