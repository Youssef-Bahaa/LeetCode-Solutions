1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int l = 0, r = numbers.size() - 1;
5        while (l < r) {
6            int mid = (l + r) / 2;
7            if (numbers[l] + numbers[r] < target)
8                l++;
9            else if (numbers[l] + numbers[r] > target)
10                r--;
11            else
12                break;
13        }
14        vector<int> v;
15        v.push_back(l + 1);
16        v.push_back(r + 1);
17        return v;
18    }
19};