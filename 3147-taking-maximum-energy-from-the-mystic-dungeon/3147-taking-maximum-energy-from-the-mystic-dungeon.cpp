class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();

        for (int i = n - k - 1; i >= 0; i--) {
            energy[i] += energy[i + k];
        }

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, energy[i]);
        }

        return ans;
    }
};