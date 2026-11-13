class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int n = nums.size();

        int inc = 1;
        int prev = 0;
        int ans = 0;

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                inc++;
            }
            else {
                prev = inc;
                inc = 1;
            }

            // Case 1: Two subarrays inside one increasing segment
            ans = max(ans, inc / 2);

            // Case 2: Two adjacent increasing segments
            ans = max(ans, min(prev, inc));
        }

        return ans;
    }
};