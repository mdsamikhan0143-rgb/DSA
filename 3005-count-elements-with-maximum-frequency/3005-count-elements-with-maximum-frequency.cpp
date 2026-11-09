class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        int maxi = 0;

        // Count frequencies
        for (int x : nums) {
            mp[x]++;
            maxi = max(maxi, mp[x]);
        }

        // Calculate total maximum frequency
        int ans = 0;

        for (auto it : mp) {
            if (it.second == maxi) {
                ans += it.second;
            }
        }

        return ans;
    }
};