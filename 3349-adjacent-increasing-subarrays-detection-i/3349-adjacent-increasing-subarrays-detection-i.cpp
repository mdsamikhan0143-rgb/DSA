class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        for (int i = 0; i + 2 * k <= n; i++) {

            bool first = true;
            bool second = true;

            // Check first subarray
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    first = false;
                    break;
                }
            }

            // Check second subarray
            for (int j = i + k; j < i + 2 * k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    second = false;
                    break;
                }
            }

            if (first && second) {
                return true;
            }
        }

        return false;
    }
};