class Solution {
public:
    int compareVersion(string version1, string version2) {
        string collect = "";
        version1 += ".";
        version2 += ".";
        vector<int> num1;
        vector<int> num2;
        for (auto i : version1) {
            if (i == '.') {
                num1.push_back(stoi(collect));
                collect = "";
            } else
                collect += i;
        }
        collect = "";
        for (auto i : version2) {
            if (i == '.') {
                num2.push_back(stoi(collect));
                collect = "";
            } else
                collect += i;
        }
        for(auto i :num1 )cout<<i <<" ";

        while (num1.size() < num2.size())
            num1.push_back(0);
        while (num1.size() > num2.size())
            num2.push_back(0);

        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] < num2[i])
                return -1;
            if (num1[i] > num2[i])
                return 1;
        }

        return 0;
    }
};