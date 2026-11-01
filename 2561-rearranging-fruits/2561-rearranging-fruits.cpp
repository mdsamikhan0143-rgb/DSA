class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int mn = INT_MAX;

        for (int x : basket1) {
            mp[x]++;
            mn = min(mn, x);
        }

        for (int x : basket2) {
            mp[x]--;
            mn = min(mn, x);
        }

        vector<int> v;

        for (auto it : mp) {
            if (it.second % 2 != 0)
                return -1;

            for (int i = 0; i < abs(it.second) / 2; i++) {
                v.push_back(it.first);
            }
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        int m = v.size();

        for (int i = 0; i < m / 2; i++) {
            ans += min(v[i], 2 * mn);
        }

        return ans;
    }
};