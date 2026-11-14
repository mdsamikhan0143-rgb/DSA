class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int last = INT_MIN;
        int ans = 0;

        for (int x : nums) {

            int smallest = x - k;
            int largest = x + k;

            int curr = max(smallest, last + 1);

            if (curr <= largest) {
                ans++;
                last = curr;
            }
        }

        return ans;
    }
};