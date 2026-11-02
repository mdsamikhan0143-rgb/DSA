
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        vector<int> powers;

        // Extract powers of 2 from n
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            long long product = 1;

            for (int i = q[0]; i <= q[1]; i++) {
                product = (product * powers[i]) % MOD;
            }

            ans.push_back(product);
        }

        return ans;
    }
};
