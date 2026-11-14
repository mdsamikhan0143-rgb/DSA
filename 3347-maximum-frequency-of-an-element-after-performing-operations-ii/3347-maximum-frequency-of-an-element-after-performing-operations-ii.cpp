class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        map<long long, int> events;
        unordered_map<long long, int> freq;

        // Build frequency and difference events
        for (int x : nums) {

            freq[x]++;

            events[(long long)x - k]++;
            events[(long long)x + k + 1]--;

            // Ensure existing values are also checked
            events[x] += 0;
        }

        int ans = 0;
        int active = 0;

        // Sweep through all candidate positions
        for (auto& [pos, change] : events) {

            active += change;

            int existing = freq[pos];

            int possible = min(
                active,
                existing + numOperations
            );

            ans = max(ans, possible);
        }

        return ans;
    }
};