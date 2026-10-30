
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();

        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int a = min(conflictingPairs[i][0], conflictingPairs[i][1]);
            int b = max(conflictingPairs[i][0], conflictingPairs[i][1]);

            adj[a].push_back({b, i});
        }

        long long ans = 0;
        vector<long long> gain(m, 0);

        int mn1 = n + 1;
        int mn2 = n + 1;
        int id = -1;

        for (int i = n; i >= 1; i--) {

            for (auto [b, idx] : adj[i]) {
                if (b < mn1) {
                    mn2 = mn1;
                    mn1 = b;
                    id = idx;
                }
                else if (b < mn2) {
                    mn2 = b;
                }
            }

            ans += mn1 - i;

            if (id != -1) {
                gain[id] += mn2 - mn1;
            }
        }

        long long best = 0;

        for (long long x : gain) {
            best = max(best, x);
        }

        return ans + best;
    }
};
