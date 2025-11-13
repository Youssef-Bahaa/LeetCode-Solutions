class Solution {
public:
    int maxOperations(string s) {
        int one_cnt = 0 , ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '1')one_cnt++;
            else {
                ans += one_cnt;
                while(i < s.size() and s[i] == '0')i++;
                i--;
            }
        }
        return ans;
    }
};