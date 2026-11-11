class Solution {
public:
    int m, n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int r, int c) {

        visited[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific Ocean DFS
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
        }

        // Atlantic Ocean DFS
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j);
        }

        // Find cells reachable from both oceans
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};