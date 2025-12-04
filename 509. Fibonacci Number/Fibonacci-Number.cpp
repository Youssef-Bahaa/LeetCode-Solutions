1class Solution {
2public:
3    int fib(int n) {
4        if (!n)
5            return 0;
6        if (n == 1)
7            return 1;
8
9        int first = 0;
10        int second = 1;
11        int sum = 1;
12        for (int i = 2; i <= n; i++) {
13            sum = first + second;
14            first = second;
15            second = sum;
16        }
17
18        return sum;
19    }
20};