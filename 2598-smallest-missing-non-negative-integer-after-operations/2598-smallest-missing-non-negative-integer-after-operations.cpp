class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int n = nums.size();

        vector<int> freq(value, 0);

        // Calculate normalized remainders
        for (int x : nums) {
            int rem = ((x % value) + value) % value;
            freq[rem]++;
        }

        // Find the smallest missing non-negative integer
        for (int i = 0; i <= n; i++) {

            int rem = i % value;

            if (freq[rem] == 0) {
                return i;
            }

            freq[rem]--;
        }

        return n;
    }
};