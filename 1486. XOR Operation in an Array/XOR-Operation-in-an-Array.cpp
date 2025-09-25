class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++)
            arr.push_back(start + 2 * i);
        for (int i = 0 ; i < arr.size(); i++)
            ans = ans ^ arr[i];
        return ans;        
    }
};