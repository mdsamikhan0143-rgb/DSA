class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        // Store numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // Calculate (n-1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        // Convert k into 0-based indexing
        k--;

        string ans = "";

        while (true) {

            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            if (nums.empty()) {
                break;
            }

            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;
    }
};