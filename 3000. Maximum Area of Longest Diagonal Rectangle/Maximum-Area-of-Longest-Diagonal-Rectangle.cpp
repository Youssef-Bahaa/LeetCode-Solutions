class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int l, w;
        double dig = 0;
        l = w = dig = 0;
        for (auto i : dimensions) {
            double cdig = (i[0] * i[0] + i[1] * i[1]);
            if (cdig > dig or (cdig == dig and (i[0] * i[1]) > l * w)) {
                dig = (i[0] * i[0] + i[1] * i[1]);
                l = i[0];
                w = i[1];
            }
        }
        return l * w;
    }
};