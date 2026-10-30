
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        vector<int> last(32, -1);

        for (int i = n - 1; i >= 0; i--) {

            int farthest = i;

            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1LL << bit)) {
                    last[bit] = i;
                }

                farthest = max(farthest, last[bit]);
            }

            ans[i] = farthest - i + 1;
        }

        return ans;
    }
};
