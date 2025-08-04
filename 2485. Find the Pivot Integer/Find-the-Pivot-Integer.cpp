class Solution {
public:
    int pivotInteger(int n) {
        int f = n * (n + 1) / 2;

        for (int i = 1; i <= n; i++) {
            int cur = i * (i + 1) / 2;
            int tempf = f - cur + i;
            if (tempf == cur)
                return i;
        }
        return -1;
    }
};