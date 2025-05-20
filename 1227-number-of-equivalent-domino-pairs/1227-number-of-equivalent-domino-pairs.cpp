class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string,int> mp;
        int ans=0;
        for(int i = 0 ; i < dominoes.size(); i++){
            if(dominoes[i][1] > dominoes[i][0])swap(dominoes[i][1] , dominoes[i][0]);
            mp[ to_string(dominoes[i][0]) + to_string(dominoes[i][1]) ] ++;
        }
            
        for(auto i : mp){
            int count = i.second;
            ans += (count * (count - 1)) / 2;
        }
        return ans;
    }
};