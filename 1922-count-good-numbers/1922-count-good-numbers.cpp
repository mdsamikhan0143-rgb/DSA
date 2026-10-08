class Solution {
public:

    long long power(long long a, long long b) {
        long long ans = 1;
        long long mod = 1000000007;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b = b / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1000000007;

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};