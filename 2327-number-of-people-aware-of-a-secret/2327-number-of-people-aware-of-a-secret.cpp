class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);

        dp[1] = 1;

        long long share = 0;

        for (int i = 2; i <= n; i++) {

            // People who can start sharing
            if (i - delay >= 1) {
                share = (share + dp[i - delay]) % MOD;
            }

            // People who forget the secret
            if (i - forget >= 1) {
                share = (share - dp[i - forget] + MOD) % MOD;
            }

            // New people who learn the secret
            dp[i] = share;
        }

        long long ans = 0;

        // Count people who have not forgotten
        for (int i = max(1, n - forget + 1); i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};