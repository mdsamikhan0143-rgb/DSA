class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;

        for (int x : nums) {
            if (ans.empty() || ans.back() != x) {
                ans.push_back(x);
            }
            else {
                if (count(ans.begin(), ans.end(), x) <k) {
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};