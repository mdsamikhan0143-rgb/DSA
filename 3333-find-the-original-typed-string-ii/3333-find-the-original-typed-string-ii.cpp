
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;

        vector<int> groups;
        int n = word.size();

        // Count consecutive groups
        for (int i = 0; i < n; ) {
            int j = i;

            while (j < n && word[j] == word[i]) {
                j++;
            }

            groups.push_back(j - i);
            i = j;
        }

        long long total = 1;

        for (int len : groups) {
            total = total * len % MOD;
        }

        // Every original string has at least one
        // character from each group.
        if (groups.size() >= k) {
            return total;
        }

        // dp[j] = ways to form a string of length j
        // using the groups processed so far.
        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int len : groups) {
            vector<int> ndp(k, 0);
            long long window = 0;

            for (int j = 1; j < k; j++) {
                window += dp[j - 1];

                if (j - len - 1 >= 0) {
                    window -= dp[j - len - 1];
                }

                window %= MOD;

                if (window < 0) {
                    window += MOD;
                }

                ndp[j] = window;
            }

            dp = ndp;
        }

        long long invalid = 0;

        for (int j = 0; j < k; j++) {
            invalid = (invalid + dp[j]) % MOD;
        }

        return (total - invalid + MOD) % MOD;
    }
};
