class Solution {
public:
    string compressedString(string word) {
        word += " ";
        string ans ;
        ans.reserve(word.size() * 2); 
        int cnt = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1] and cnt < 9) 
                cnt++;
            else {
                ans.push_back(cnt +'0');
                ans.push_back(word[i-1]);
                cnt = 1;
            }
        }
        return ans;
    }
};