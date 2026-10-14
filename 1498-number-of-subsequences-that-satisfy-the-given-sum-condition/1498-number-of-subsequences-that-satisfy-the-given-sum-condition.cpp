
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
