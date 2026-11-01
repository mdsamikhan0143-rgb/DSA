class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0;
        int sum = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            sum += fruits[right][1];

            while (left <= right) {
                int l = fruits[left][0];
                int r = fruits[right][0];

                int steps = min(
                    abs(startPos - l) + (r - l),
                    abs(startPos - r) + (r - l)
                );

                if (steps <= k)
                    break;

                sum -= fruits[left][1];
                left++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};