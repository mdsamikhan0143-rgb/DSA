class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        // Case 1: Target may not exist in nums
        int left = 0;

        for (int right = 0; right < n; right++) {

            while ((long long)nums[right] - nums[left] > 2LL * k) {
                left++;
            }

            ans = max(ans, min(numOperations, right - left + 1));
        }

        // Case 2: Target already exists in nums
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 0; i < n; i++) {

            int target = nums[i];

            int l = lower_bound(
                nums.begin(), nums.end(), (long long)target - k
            ) - nums.begin();

            int r = upper_bound(
                nums.begin(), nums.end(), (long long)target + k
            ) - nums.begin();

            int total = r - l;

            int current = freq[target] +
                          min(numOperations, total - freq[target]);

            ans = max(ans, current);
        }

        return ans;
    }
};