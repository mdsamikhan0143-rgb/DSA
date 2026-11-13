class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        int n = skill.size();
        int m = mana.size();

        vector<long long> finish(n, 0);

        for (int j = 0; j < m; j++) {

            long long start = 0;
            long long prefix = 0;

            // Find the minimum starting time
            for (int i = 0; i < n; i++) {

                start = max(start, finish[i] - prefix);

                prefix += (long long)skill[i] * mana[j];
            }

            // Update finishing times
            prefix = 0;

            for (int i = 0; i < n; i++) {

                prefix += (long long)skill[i] * mana[j];

                finish[i] = start + prefix;
            }
        }

        return finish[n - 1];
    }
};