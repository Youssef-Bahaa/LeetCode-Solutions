class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int word = 0;
        bool broken = false;
        unordered_map<char, int> freq;
        text += " ";
        for (auto i : brokenLetters)
            freq[i] = 1;

        for (auto i : text) {
            if (i == ' ') {
                if (!broken)
                    word++;
                broken = false;
            }
            if (freq[i])
                broken = true;
        }

        return word;
    }
};