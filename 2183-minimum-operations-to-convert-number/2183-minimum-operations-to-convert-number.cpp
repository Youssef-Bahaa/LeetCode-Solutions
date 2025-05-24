class Solution {
public:
    bool process(vector<bool>& vis, queue<int>& q, int goal, int op) {
        if (op == goal)
            return true;

        if (op >= 0 and op <= 1000 and !vis[op]) {
            vis[op] = 1;
            q.push(op);
        }
        return false;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {

        vector<bool> vis(1001, false);
        queue<int> q;
        int level = 1;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int temp = q.front();
                q.pop();
                for (int i = 0; i < nums.size(); i++) {
                    if (process(vis, q, goal, temp + nums[i]) or
                        process(vis, q, goal, temp - nums[i]) or
                        process(vis, q, goal, temp ^ nums[i]))
                        return level;
                }
            }
            level++;
        }

        return -1;
    }
};