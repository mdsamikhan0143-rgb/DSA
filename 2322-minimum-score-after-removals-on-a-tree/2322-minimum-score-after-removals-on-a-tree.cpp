
class Solution {
public:
    vector<int> xorSum, tin, tout;
    vector<vector<int>> adj;
    int timer = 0;

    void dfs(int node, int parent, vector<int>& nums) {
        tin[node] = timer++;
        xorSum[node] = nums[node];

        for (int next : adj[node]) {
            if (next == parent) continue;

            dfs(next, node, nums);
            xorSum[node] ^= xorSum[next];
        }

        tout[node] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        adj.resize(n);
        xorSum.resize(n);
        tin.resize(n);
        tout.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);

        int total = xorSum[0];
        int ans = INT_MAX;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a, b, c;

                if (isAncestor(i, j)) {
                    a = xorSum[j];
                    b = xorSum[i] ^ xorSum[j];
                    c = total ^ xorSum[i];
                } 
                else if (isAncestor(j, i)) {
                    a = xorSum[i];
                    b = xorSum[j] ^ xorSum[i];
                    c = total ^ xorSum[j];
                } 
                else {
                    a = xorSum[i];
                    b = xorSum[j];
                    c = total ^ xorSum[i] ^ xorSum[j];
                }

                int score = max({a, b, c}) - min({a, b, c});
                ans = min(ans, score);
            }
        }

        return ans;
    }
};
