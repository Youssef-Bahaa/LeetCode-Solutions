class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> num1;
        vector<int> num2;
        parser(num1, version1);
        parser(num2, version2);
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            int nm1 = i < num1.size() ? num1[i] : 0;
            int nm2 = i < num2.size() ? num2[i] : 0;
            if (nm1 < nm2)return -1;
            if (nm1 > nm2)return 1;
        }
        return 0;
    }
    void parser(vector<int>& num, string& s) {
        s += ".";
        string collect = "";
        for (auto i : s) {
            if (i == '.') {
                num.push_back(stoi(collect));
                collect = "";
            } else
                collect += i;
        }
    }
};