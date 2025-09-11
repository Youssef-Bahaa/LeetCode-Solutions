class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        string ans = "";
        vector<int> asci(128, 0);
        vector<char> c;

        for (auto i : s)
            if (isVowel(i))
                asci[i]++;

        for (int i = 65; i <= 122; i++) {
            if (isVowel(char(i))) {
                while (asci[i]--) {
                    c.push_back(char(i));
                }
            }
        }

        int j = 0;
        for (auto i : s) {
            if (isVowel(i))
                ans += c[j++];
            else
                ans += i;
        }
        return ans;
    }
};