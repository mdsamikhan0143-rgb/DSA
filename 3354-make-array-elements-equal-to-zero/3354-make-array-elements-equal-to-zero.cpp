class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = 0;
        int left = 0;
        int ans = 0;

        // Calculate total sum
        for (int x : nums) {
            total += x;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                int right = total - left;

                if (left == right) {
                    ans += 2;
                }
                else if (abs(left - right) == 1) {
                    ans += 1;
                }
            }

            left += nums[i];
        }

        return ans;
    }
};