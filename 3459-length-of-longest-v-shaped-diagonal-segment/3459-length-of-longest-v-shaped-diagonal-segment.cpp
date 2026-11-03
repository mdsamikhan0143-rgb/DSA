
class Solution {
public:
    int n, m;
    vector<vector<vector<vector<int>>>> dp;

    int dr[4] = {1, 1, -1, -1};
    int dc[4] = {1, -1, -1, 1};

    int dfs(int r, int c, int dir, int turn,
            vector<vector<int>>& grid) {

        if (dp[r][c][dir][turn] != -1)
            return dp[r][c][dir][turn];

        int ans = 1;

        int next = (grid[r][c] == 1) ? 2 :
                   (grid[r][c] == 2) ? 0 : 2;

        // Continue in the same direction
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            grid[nr][nc] == next) {

            ans = max(ans, 1 + dfs(nr, nc, dir, turn, grid));
        }

        // Make one clockwise 90-degree turn
        if (turn == 1) {
            int ndir = (dir + 1) % 4;

            nr = r + dr[ndir];
            nc = c + dc[ndir];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == next) {

                ans = max(ans, 1 + dfs(nr, nc, ndir, 0, grid));
            }
        }

        return dp[r][c][dir][turn] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<vector<int>>>(
            m, vector<vector<int>>(4, vector<int>(2, -1))
        ));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, dfs(i, j, d, 1, grid));
                    }
                }
            }
        }

        return ans;
    }
};
