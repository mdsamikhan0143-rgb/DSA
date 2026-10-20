
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        gaps[0] = startTime[0];

        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }

        gaps[n] = eventTime - endTime[n - 1];

        vector<int> left(n + 1, 0), right(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            left[i] = gaps[i];
            if (i > 0)
                left[i] = max(left[i], left[i - 1]);
        }

        for (int i = n; i >= 0; i--) {
            right[i] = gaps[i];
            if (i < n)
                right[i] = max(right[i], right[i + 1]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int duration = endTime[i] - startTime[i];
            int freeTime = gaps[i] + gaps[i + 1];

            int largestOtherGap = 0;

            if (i > 0)
                largestOtherGap = max(largestOtherGap, left[i - 1]);

            if (i + 2 <= n)
                largestOtherGap = max(largestOtherGap, right[i + 2]);

            if (largestOtherGap >= duration)
                freeTime += duration;

            ans = max(ans, freeTime);
        }

        return ans;
    }
};
