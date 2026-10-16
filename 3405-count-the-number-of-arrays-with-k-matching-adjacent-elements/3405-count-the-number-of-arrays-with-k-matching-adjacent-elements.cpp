
class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }

    long long nCr(int n, int r) {
        long long factN = 1, factR = 1, factDiff = 1;

        for (int i = 1; i <= n; i++) {
            factN = (factN * i) % MOD;
        }

        for (int i = 1; i <= r; i++) {
            factR = (factR * i) % MOD;
        }

        for (int i = 1; i <= n - r; i++) {
            factDiff = (factDiff * i) % MOD;
        }

        long long denominator = (factR * factDiff) % MOD;

        return (factN * power(denominator, MOD - 2)) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;

        long long ways = nCr(n - 1, k);
        ways = (ways * m) % MOD;
        ways = (ways * power(m - 1, n - 1 - k)) % MOD;

        return ways;
    }
};
