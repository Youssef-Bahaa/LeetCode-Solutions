class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        for (auto i : nums1)
            st1.insert(i);
        for (auto i : nums2)
            st2.insert(i);

        int left = 0, right = 0;

        for (auto i : nums1) {
            if (st2.count(i))
                left++;
        }
        for (auto i : nums2) {
            if (st1.count(i))
                right++;
        }

        return {left, right};
    }
};