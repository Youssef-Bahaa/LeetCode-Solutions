class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1;
        vector<char> ans;
        chars.push_back(' ');
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1]) {
                cnt++;
            } else {
                ans.push_back(chars[i - 1]);
                if (cnt > 1) {
                    string num = to_string(cnt);
                    for (auto c : num)
                        ans.push_back(c);
                }
                cnt = 1;
            }
        }
        chars.clear();
        for (auto i : ans)
            chars.push_back(i);

        return ans.size();
    }
};