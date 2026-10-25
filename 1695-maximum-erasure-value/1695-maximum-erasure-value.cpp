
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, sum = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (seen.count(nums[right])) {
                sum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }

            seen.insert(nums[right]);
            sum += nums[right];

            ans = max(ans, sum);
        }

        return ans;
    }
};
