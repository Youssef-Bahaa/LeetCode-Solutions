class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string ans = "/", temp = "";
        int lastidx = (int)path.size() - 1;
        if (path[lastidx] != '/')
            path += '/';

        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!v.empty() and temp == "..")
                    v.pop_back();

                else if (temp != "" and temp != "." and temp != "..")
                    v.push_back(temp);
                temp = "";

            } else
                temp += path[i];
        }

        for (int i = 0; i < v.size(); i++) {
            ans += v[i];

            if (i < (int)v.size() - 1)
                ans += '/';
        }
        return ans;
    }
};