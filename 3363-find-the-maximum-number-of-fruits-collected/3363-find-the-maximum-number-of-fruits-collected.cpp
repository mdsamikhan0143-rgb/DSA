
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;

        // Child 1: Diagonal
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        // Child 2: Top-right to bottom-right
        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][n - 1] = fruits[0][n - 1];

        for (int i = 1; i < n; i++) {
            int low = (i == n - 1) ? n - 1 : max(i + 1, n - 1 - i);

            for (int j = low; j < n; j++) {
                int best = -1;

                for (int k = max(0, j - 1); k <= min(n - 1, j + 1); k++) {
                    if (dp[i - 1][k] != -1) {
                        best = max(best, dp[i - 1][k]);
                    }
                }

                if (best != -1)
                    dp[i][j] = best + fruits[i][j];
            }
        }

        ans += dp[n - 1][n - 1] - fruits[n - 1][n - 1];

        // Child 3: Bottom-left to bottom-right
        dp.assign(n, vector<int>(n, -1));

        dp[n - 1][0] = fruits[n - 1][0];

        for (int j = 1; j < n; j++) {
            int low = (j == n - 1) ? n - 1 : max(j + 1, n - 1 - j);

            for (int i = low; i < n; i++) {
                int best = -1;

                for (int k = max(0, i - 1); k <= min(n - 1, i + 1); k++) {
                    if (dp[k][j - 1] != -1) {
                        best = max(best, dp[k][j - 1]);
                    }
                }

                if (best != -1)
                    dp[i][j] = best + fruits[i][j];
            }
        }

        ans += dp[n - 1][n - 1] - fruits[n - 1][n - 1];

        return ans;
    }
};
