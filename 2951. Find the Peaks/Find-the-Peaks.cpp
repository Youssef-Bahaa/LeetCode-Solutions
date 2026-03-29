1class Solution {
2public:
3    vector<int> findPeaks(vector<int>& m) {
4        vector<int> ans;
5        for(int i = 1 ; i < m.size() - 1; i++){
6            if(m[i] > m[i - 1] && m[i] > m[i + 1])ans.push_back(i);
7        }
8        return ans;
9    }
10};