class Solution {
public:
    int countSubarrays(vector<int>& nums, long long limit) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > limit) {
                subarrays++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums) {
            high += num;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countSubarrays(nums, mid) <= k) {
                high = mid - 1;  // Try a smaller maximum sum
            } else {
                low = mid + 1;   // Need a larger maximum sum
            }
        }

        return static_cast<int>(low);
    }
};