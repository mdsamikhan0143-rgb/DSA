
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;

        for (int x : nums) {
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        int ans = max(even, odd);

        int parity = nums[0] % 2;
        int alternating = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 != parity) {
                alternating++;
                parity = nums[i] % 2;
            }
        }

        return max(ans, alternating);
    }
};
