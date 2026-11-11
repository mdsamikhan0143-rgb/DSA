class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3)
            return 0;

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // BFS using min heap
        while (!pq.empty()) {

            auto [h, x, y] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n ||
                    visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;

                // Calculate trapped water
                water += max(0, h - heightMap[nx][ny]);

                // Push effective height
                pq.push({
                    max(h, heightMap[nx][ny]),
                    nx,
                    ny
                });
            }
        }

        return water;
    }
};