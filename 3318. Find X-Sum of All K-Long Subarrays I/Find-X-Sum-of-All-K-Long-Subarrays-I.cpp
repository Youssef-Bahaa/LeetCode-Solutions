class Solution {
public:
    int xsum(unordered_map<int, int>& mp, int x) {
        priority_queue<pair<int,int>> pq;
        for(auto& i : mp) pq.push({i.second, i.first});
            
        int sum = 0;
        while (x-- and pq.size()) {
            auto [freq,val] = pq.top();
            pq.pop();
           sum += val * freq;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size() ; i++) {
            mp[nums[i]]++;
            if(i >= k - 1){
                ans.push_back(xsum(mp,x));
                mp[nums[i - k + 1]]--;
            }
        }
        return ans;
    }
};