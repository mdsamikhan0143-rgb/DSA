class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            long long required =
                (success + spells[i] - 1) / spells[i];

            int idx = lower_bound(
                potions.begin(),
                potions.end(),
                required
            ) - potions.begin();

            ans[i] = m - idx;
        }

        return ans;
    }
};