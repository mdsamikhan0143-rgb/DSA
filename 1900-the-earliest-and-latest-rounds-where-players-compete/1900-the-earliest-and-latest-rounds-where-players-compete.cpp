
class Solution {
public:
    int dp[29][29][29][2];

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(dp, -1, sizeof(dp));
        auto ans = dfs(n, firstPlayer, secondPlayer);
        return {ans.first, ans.second};
    }

    pair<int, int> dfs(int n, int a, int b) {
        if (a + b == n + 1) return {1, 1};
        if (a > b) swap(a, b);

        int &e = dp[n][a][b][0];
        int &l = dp[n][a][b][1];

        if (e != -1) return {e, l};

        e = INT_MAX;
        l = INT_MIN;

        int nextN = (n + 1) / 2;

        for (int mask = 0; mask < (1 << (n / 2)); mask++) {
            vector<int> winners;

            for (int i = 1; i <= n / 2; i++) {
                int j = n + 1 - i;

                if (i == a || i == b) winners.push_back(i);
                else if (j == a || j == b) winners.push_back(j);
                else winners.push_back((mask & (1 << (i - 1))) ? i : j);
            }

            if (n % 2) winners.push_back(n / 2 + 1);
            sort(winners.begin(), winners.end());

            int na = 0, nb = 0;
            for (int i = 0; i < nextN; i++) {
                if (winners[i] == a) na = i + 1;
                if (winners[i] == b) nb = i + 1;
            }

            if (na == 0 || nb == 0) continue;

            auto res = dfs(nextN, na, nb);
            e = min(e, res.first + 1);
            l = max(l, res.second + 1);
        }

        return {e, l};
    }
};
