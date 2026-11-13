class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();

        vector<int> ans(n, 1);

        // Stores days when we can dry a lake
        set<int> dryDays;

        // Stores the last rainy day for each lake
        unordered_map<int, int> lastRain;

        for (int i = 0; i < n; i++) {

            int lake = rains[i];

            // No rain: we can dry one lake
            if (lake == 0) {
                dryDays.insert(i);
                continue;
            }

            // Rain on an already full lake => flood
            if (lastRain.count(lake)) {

                int prevDay = lastRain[lake];

                // Find the earliest available dry day
                // after the previous rain
                auto it = dryDays.upper_bound(prevDay);

                if (it == dryDays.end()) {
                    return {};
                }

                // Dry this lake
                ans[*it] = lake;

                // Remove the used dry day
                dryDays.erase(it);
            }

            // Update the last rainy day
            lastRain[lake] = i;

            // Rainy days must contain -1
            ans[i] = -1;
        }

        return ans;
    }
};