class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            // Destination reached
            if (r == n - 1 && c == n - 1) {
                return time;
            }

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;

                    int newTime = max(time, grid[nr][nc]);

                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1;
    }
};