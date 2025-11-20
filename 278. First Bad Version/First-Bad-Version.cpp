// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1 , r = n , idx = 1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            int ans = isBadVersion(mid);
            if(ans == 1){
                r = mid - 1;
                idx = mid;
            }
            else l = mid + 1;
            
        }
        return idx;
    }
};