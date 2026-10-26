
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        int maxi = INT_MIN;

        for (int num : nums) {
            maxi = max(maxi, num);

            if (num > 0 && st.insert(num).second) {
                sum += num;
            }
        }

        return sum > 0 ? sum : maxi;
    }
};
