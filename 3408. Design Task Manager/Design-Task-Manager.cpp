class TaskManager {
public:
    priority_queue<pair<int, int>> q;
    unordered_map<int, pair<int, int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto i : tasks) {
            int userId = i[0];
            int taskId = i[1];
            int priority = i[2];
            q.push({priority, taskId});
            mp[taskId] = {userId, priority};
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        q.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        mp[taskId].second = newPriority;
        q.push({newPriority, taskId});
    }

    void rmv(int taskId) {
         mp[taskId].second = -1; 
    }

    int execTop() {
        while (!q.empty()) {
            auto [priority, taskId] = q.top();
            auto it = mp.find(taskId);

            if (it == mp.end() or it->second.second != priority) {     
                q.pop();
                continue;
            }
            int userId = it->second.first;
            q.pop();
            it->second.second = -1; 
            return userId;
               
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */