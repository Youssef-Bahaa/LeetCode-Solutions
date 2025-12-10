1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_set<char> st;
5        int l = 0;
6        int res = 0;
7        for(int r = 0 ; r < s.size();r++){
8            while(st.count(s[r])){
9                st.erase(s[l]);
10                l++;
11            }
12            st.insert(s[r]);
13            res = max(res,r - l + 1);
14        }
15
16        return res;
17    }
18};