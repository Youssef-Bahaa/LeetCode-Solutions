class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalpha(s[i]))
                i++;
            if (!isalpha(s[j]))
                j--;
            else if  (isalpha(s[i]) and isalpha(s[j]))
                swap(s[i++], s[j--]);
        }
        return s;
    }
};