class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int cnt = 0 ; 
        while(n){
            int dig = (n % 10) * pow(10,cnt++);
            if(dig == 0){
                if(cnt == 1 and n % 10 ) ans.push_back(dig);
            }
            else ans.push_back(dig);
            n /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};