
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        gaps[0] = startTime[0];

        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        gaps[n] = eventTime - endTime[n - 1];

        int sum = 0, ans = 0;

        for (int i = 0; i <= n; i++) {
            sum += gaps[i];

            if (i >= k + 1) {
                sum -= gaps[i - k - 1];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
