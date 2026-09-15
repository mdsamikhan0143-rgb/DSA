class Solution {
public:
    // Your code: calculate days needed for a capacity
    int requiredDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }

        return days;
    }

    // LeetCode calls this function
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int w : weights) {
            high += w;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (requiredDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};