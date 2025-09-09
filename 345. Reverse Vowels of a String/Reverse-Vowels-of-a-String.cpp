class Solution {
public:
    bool vowel(char s) {
        s = tolower(s);
        return s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u';
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (!vowel(s[i]))
                i++;
            if (!vowel(s[j]))
                j--;
            else if (vowel(s[i]) and vowel(s[j]))
                swap(s[i++], s[j--]);
        }
        return s;
    }
};