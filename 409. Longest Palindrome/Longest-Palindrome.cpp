class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char,int>freq;
        bool odd = false;
        for(auto i : s )freq[char(i)]++;
        for(auto i : freq ){
            ans += i.second;
            if(i.second % 2)ans--,odd=1;
        }
        if(odd)return ans + 1;
        return ans;
    }
};