class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = 0, ans = 0;
        vector<int>freq(101,0);
        for (auto i : nums) {
            freq[i]++;
            maxi = max(maxi, freq[i]);
        }
        for (auto i : freq)
            if (i == maxi)
                ans+= i;

        return ans;
    }
};