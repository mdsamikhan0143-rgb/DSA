
class Solution {
public:
    int ans = 0;
    int maxOR = 0;

    void solve(vector<int>& nums, int i, int currOR) {
        if (i == nums.size()) {
            if (currOR == maxOR) {
                ans++;
            }
            return;
        }

        // Include current element
        solve(nums, i + 1, currOR | nums[i]);

        // Exclude current element
        solve(nums, i + 1, currOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums) {
            maxOR |= x;
        }

        solve(nums, 0, 0);

        return ans;
    }
};
