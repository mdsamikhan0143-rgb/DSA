
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int m = nums.size();

        vector<long long> left(m), right(m);

        priority_queue<int> maxHeap;
        long long sum = 0;

        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n) {
                left[i] = sum;
            }
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;

        for (int i = m - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n) {
                right[i] = sum;
            }
        }

        long long ans = LLONG_MAX;

        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }

        return ans;
    }
};
