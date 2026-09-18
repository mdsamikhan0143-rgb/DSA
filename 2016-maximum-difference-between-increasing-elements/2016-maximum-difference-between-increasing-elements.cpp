class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = nums[0];
        int maxDiff = -1;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] > minValue) {
                maxDiff = max(maxDiff, nums[j] - minValue);
            }

            minValue = min(minValue, nums[j]);
        }

        return maxDiff;
    }
};