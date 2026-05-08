1class Solution {
2public:
3    // int dp[10][10][10]{-1};
4    bool val(int num1, int num2, int num3) {
5        return (num2 > num1 and num2 > num3) or (num2 < num1 and num2 < num3);
6    }
7    int totalWaviness(int num1, int num2) {
8        int cnt = 0;
9        for (int i = num1; i <= num2; i++) {
10            string num = to_string(i);
11            if (num.size() < 3)
12                continue;
13            int res1 = val(num[0], num[1], num[2]);
14            int res2 = val(num[1], num[2], num[3]);
15            int res3 = val(num[2], num[3], num[4]);
16            if (num.size() == 3)
17                cnt += res1;
18            else if (num.size() == 4)
19                cnt += res1 + res2;
20            else if (num.size() == 5)
21                cnt += res1 + res2 + res3;
22        }
23        return cnt;
24    }
25};