class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            int diff = abs(nums[i] - nums[next]);

            answer = max(answer, diff);
        }

        return answer;
    }
};
