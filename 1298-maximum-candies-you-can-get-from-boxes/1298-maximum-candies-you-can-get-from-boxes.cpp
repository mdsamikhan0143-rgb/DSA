
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        int ans = 0;

        queue<int> q;
        vector<bool> hasBox(n, false);
        vector<bool> used(n, false);

        for (int box : initialBoxes) {
            hasBox[box] = true;

            if (status[box] == 1) {
                q.push(box);
                used[box] = true;
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            ans += candies[box];

            // Collect keys
            for (int key : keys[box]) {
                status[key] = 1;

                if (hasBox[key] && !used[key]) {
                    q.push(key);
                    used[key] = true;
                }
            }

            // Collect contained boxes
            for (int b : containedBoxes[box]) {
                hasBox[b] = true;

                if (status[b] == 1 && !used[b]) {
                    q.push(b);
                    used[b] = true;
                }
            }
        }

        return ans;
    }
};
