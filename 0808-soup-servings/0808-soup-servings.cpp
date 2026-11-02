
class Solution {
public:
    double dp[200][200];

    double solve(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;

        if (a <= 0)
            return 1.0;

        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        return dp[a][b] = 0.25 * (
            solve(a - 4, b) +
            solve(a - 3, b - 1) +
            solve(a - 2, b - 2) +
            solve(a - 1, b - 3)
        );
    }

    double soupServings(int n) {
        if (n >= 4800)
            return 1.0;

        int m = (n + 24) / 25;

        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                dp[i][j] = -1.0;
            }
        }

        return solve(m, m);
    }
};
