class Solution {
public:
    bool isvowel(char s) {
        return s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;

        for (char i : s)
            mp[i]++;

        int vfreq = 0, confreq = 0;

        for (auto i : mp) {
            char c = i.first;
            int freq = i.second;
            if (isvowel(c))
                vfreq = max(vfreq, freq);

            else
                confreq = max(confreq, freq);
        }

        return vfreq + confreq;
    }
};