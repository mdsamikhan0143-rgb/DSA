class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        map<int, long long> freq;

        for (int x : power) {
            freq[x]++;
        }

        vector<int> values;
        vector<long long> damage;

        for (auto& [x, count] : freq) {
            values.push_back(x);
            damage.push_back(1LL * x * count);
        }

        int n = values.size();

        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            int x = values[i - 1];

            int j = lower_bound(
                values.begin(),
                values.begin() + i - 1,
                x - 2
            ) - values.begin();

            long long take = damage[i - 1] + dp[j];

            long long skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[n];
    }
};