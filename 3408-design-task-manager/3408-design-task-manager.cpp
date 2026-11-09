
class TaskManager {
public:
    // {priority, taskId, userId}
    priority_queue<tuple<int, int, int>> pq;

    // taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> mp;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];

            pq.push({priority, taskId, userId});
            mp[taskId] = {userId, priority};
        }
    }

    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId});
        mp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        int userId = mp[taskId].first;

        mp[taskId].second = newPriority;

        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        mp.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop();

            // Validate task ID, user ID and priority
            if (mp.count(taskId) &&
                mp[taskId].first == userId &&
                mp[taskId].second == priority) {

                mp.erase(taskId);
                return userId;
            }
        }

        return -1;
    }
};