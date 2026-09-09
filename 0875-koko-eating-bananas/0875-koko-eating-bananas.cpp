class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;

        for (int bananas : piles) {
            totalH += (bananas + (long long)speed - 1) / speed;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHours = calculateTotalHours(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;  // Try a slower speed
            } else {
                low = mid + 1;   // Need a faster speed
            }
        }

        return low;
    }
};