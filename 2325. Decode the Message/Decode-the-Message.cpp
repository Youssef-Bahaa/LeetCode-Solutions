class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        string ans = "";
        int cnt = 0;
        for (auto i : key) {
            if (i == ' ' or mp[i])
                continue;

            mp[i] = char('a' + cnt++);
        }

        for (auto i : message) {
            if (i == ' ') {
                ans += i;
                continue;
            }
            ans += mp[i];
        }

        return ans;
    }
};