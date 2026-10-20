
class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& events,
              vector<vector<int>>& dp) {
        if (i == events.size() || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int skip = solve(i + 1, k, events, dp);

        int next = i + 1;
        int left = i + 1, right = events.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > events[i][1])
                right = mid;
            else
                left = mid + 1;
        }

        next = left;

        int attend = events[i][2] +
                     solve(next, k - 1, events, dp);

        return dp[i][k] = max(skip, attend);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return solve(0, k, events, dp);
    }
};
