
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto &q : queries) {
            long long l = q[0];
            long long r = q[1];

            long long total = 0;

            for (long long i = 1, p = 1; p <= r; i++, p *= 4) {
                long long left = max(l, p);
                long long right = min(r, p * 4 - 1);

                if (left <= right) {
                    total += (right - left + 1) * i;
                }
            }

            ans += (total + 1) / 2;
        }

        return ans;
    }
};
