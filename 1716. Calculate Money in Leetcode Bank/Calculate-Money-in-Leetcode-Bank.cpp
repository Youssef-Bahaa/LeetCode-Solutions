class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int low = 28;
        int high = 28 + (weeks - 1) * 7;
        int res = (weeks * (low + high)) / 2; 
        int monday = weeks + 1;
        int day = 0;
        while(day < n % 7){
            res += monday  + day;
            day++;
        }
        return res;
    }
};