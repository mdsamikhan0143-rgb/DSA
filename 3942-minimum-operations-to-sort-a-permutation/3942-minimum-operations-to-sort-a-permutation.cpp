
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> rev(nums.rbegin(), nums.rend());
        vector<vector<int>> arr = {nums, rev};

        vector<vector<bool>> target(2, vector<bool>(n, false));

        // Find sorted rotations of nums and reversed nums
        for (int t = 0; t < 2; t++) {
            int k = find(arr[t].begin(), arr[t].end(), 0)
                    - arr[t].begin();

            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (arr[t][(k + i) % n] != i) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                target[t][k] = true;
        }

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [type, shift] = q.front();
            q.pop();

            if (target[type][shift])
                return dist[type][shift];

            // Operation 1: Rotate left by one
            int nextShift = (shift + 1) % n;

            if (dist[type][nextShift] == -1) {
                dist[type][nextShift] = dist[type][shift] + 1;
                q.push({type, nextShift});
            }

            // Operation 2: Reverse the entire array
            int nextType = 1 - type;
            nextShift = (n - shift) % n;

            if (dist[nextType][nextShift] == -1) {
                dist[nextType][nextShift] = dist[type][shift] + 1;
                q.push({nextType, nextShift});
            }
        }

        return -1;
    }
};
