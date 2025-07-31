class Solution {
public:
    string b(int n, int base) {
        string s = "";
        while (n) {
            s += char(n % base + '0');
            n /= base;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    bool pal(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {

        for (int i = 2; i <= n - 2; i++) {
            string s = b(n, i);
            if (pal(s) == 0)
                return false;
        }
        return true;
    }
};