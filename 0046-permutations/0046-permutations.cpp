
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        solve(nums, temp, used, ans);

        return ans;
    }

    void solve(vector<int>& nums, vector<int>& temp,
               vector<bool>& used, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;

                solve(nums, temp, used, ans);

                temp.pop_back();
                used[i] = false;
            }
        }
    }
};
