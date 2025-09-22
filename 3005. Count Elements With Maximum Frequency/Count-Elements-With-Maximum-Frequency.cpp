class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = 0, ans = 0;
        unordered_map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
            maxi = max(maxi, freq[i]);
        }
        for (auto i : freq)
            if (i.second == maxi)
                ans+= i.second;

        return ans;
    }
};