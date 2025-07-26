class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            for(int j = 0 ; j < nums2.size() ; j++){
                cnt +=  (nums1[i] % (k * nums2[j])) == 0;
            }
        }
        return cnt;
    }
};