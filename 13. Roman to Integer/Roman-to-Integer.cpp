class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> freq;
        freq['I'] = 1;
        freq['V'] = 5;
        freq['X'] = 10;
        freq['L'] = 50;
        freq['C'] = 100;
        freq['D'] = 500;
        freq['M'] = 1000;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 and freq[s[i]] < freq[s[i + 1]]) {
                sum += freq[s[i + 1]] - freq[s[i]];
                i++;
            } 
            else sum += freq[s[i]];

        }
        return sum;
    }
};