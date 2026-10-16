
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k < 0 || k >= n) return 0;

        long long ans = m;
        long long comb = 1;

        for (int i = 1; i <= k; i++) {
            comb = comb * (n - i) % MOD;
            comb = comb * power(i, MOD - 2) % MOD;
        }

        ans = ans * comb % MOD;
        ans = ans * power(m - 1, n - 1 - k) % MOD;

        return ans;
    }
};
