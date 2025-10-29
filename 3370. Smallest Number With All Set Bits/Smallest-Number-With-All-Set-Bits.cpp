class Solution {
public:
    int smallestNumber(int n) {
        int p = 0;
        while(true){
            if(pow(2,p) - 1 >= n)return pow(2,p) - 1;
            p++;
        }
        return -1;
    }
};