class Solution {
public:
    bool possible(vector<int>& nums, int maxDiff, int p) {
        int pairs = 0;
        int i = 0;
        int n = nums.size();

        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                pairs++;
                i += 2;  // Both elements are used
            } else {
                i++;     // Try the next adjacent pair
            }

            if (pairs >= p) return true;
        }

        return pairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, mid, p)) {
                high = mid - 1;  // Try a smaller maximum difference
            } else {
                low = mid + 1;   // Allow a larger difference
            }
        }

        return low;
    }
};