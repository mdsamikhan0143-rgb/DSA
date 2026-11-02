
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto area = [&](int r1, int c1, int r2, int c2) {
            int minR = m, minC = n;
            int maxR = -1, maxC = -1;

            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j]) {
                        minR = min(minR, i);
                        minC = min(minC, j);
                        maxR = max(maxR, i);
                        maxC = max(maxC, j);
                    }
                }
            }

            if (maxR == -1) return 0;
            return (maxR - minR + 1) * (maxC - minC + 1);
        };

        int ans = INT_MAX;

        // Try all horizontal and vertical cuts
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                ans = min(ans,
                    area(0, 0, i, n - 1) +
                    area(i + 1, 0, j, n - 1) +
                    area(j + 1, 0, m - 1, n - 1));
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                ans = min(ans,
                    area(0, 0, m - 1, i) +
                    area(0, i + 1, m - 1, j) +
                    area(0, j + 1, m - 1, n - 1));
            }
        }

        // Mixed partitions
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans,
                    area(0, 0, i, n - 1) +
                    area(i + 1, 0, m - 1, j) +
                    area(i + 1, j + 1, m - 1, n - 1));

                ans = min(ans,
                    area(0, 0, i, j) +
                    area(0, j + 1, i, n - 1) +
                    area(i + 1, 0, m - 1, n - 1));

                ans = min(ans,
                    area(0, 0, m - 1, j) +
                    area(0, j + 1, i, n - 1) +
                    area(i + 1, j + 1, m - 1, n - 1));

                ans = min(ans,
                    area(0, 0, i, j) +
                    area(i + 1, 0, m - 1, j) +
                    area(0, j + 1, m - 1, n - 1));
            }
        }

        return ans;
    }
};
