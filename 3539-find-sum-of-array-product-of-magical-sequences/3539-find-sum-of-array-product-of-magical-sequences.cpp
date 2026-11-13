class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long magicalSum(int m, int k, vector<int>& nums) {

        int n = nums.size();

        vector<long long> fact(m + 1);
        vector<long long> invFact(m + 1);

        fact[0] = 1;

        for (int i = 1; i <= m; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[m] = modpow(fact[m], MOD - 2);

        for (int i = m; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        // Precompute powers of nums[i]
        vector<vector<long long>> powers(
            n, vector<long long>(m + 1, 1)
        );

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                powers[i][j] =
                    powers[i][j - 1] * nums[i] % MOD;
            }
        }

        // dp[used][carry][bits]
        vector<vector<vector<long long>>> dp(
            m + 1,
            vector<vector<long long>>(
                m + 1,
                vector<long long>(k + 1, 0)
            )
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++) {

            vector<vector<vector<long long>>> ndp(
                m + 1,
                vector<vector<long long>>(
                    m + 1,
                    vector<long long>(k + 1, 0)
                )
            );

            for (int used = 0; used <= m; used++) {

                for (int carry = 0; carry <= m; carry++) {

                    for (int bits = 0; bits <= k; bits++) {

                        if (dp[used][carry][bits] == 0)
                            continue;

                        // Choose how many times index i appears
                        for (int x = 0; x <= m - used; x++) {

                            int sum = carry + x;

                            int newCarry = sum / 2;
                            int newBits = bits + (sum % 2);

                            if (newBits > k)
                                continue;

                            long long ways =
                                powers[i][x] * invFact[x] % MOD;

                            long long value =
                                dp[used][carry][bits] * ways % MOD;

                            ndp[used + x][newCarry][newBits] =
                                (ndp[used + x][newCarry][newBits]
                                + value) % MOD;
                        }
                    }
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        // Count the remaining carry bits
        for (int carry = 0; carry <= m; carry++) {

            int remainingBits = __builtin_popcount(carry);

            if (remainingBits + 0 > k)
                continue;

            ans = (ans + dp[m][carry][k - remainingBits]) % MOD;
        }

        // Account for all permutations
        ans = ans * fact[m] % MOD;

        return ans;
    }
};