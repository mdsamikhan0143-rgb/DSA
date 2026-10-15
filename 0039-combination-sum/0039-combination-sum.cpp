class Solution {
public:
    void solve(int i, vector<int>& candidates, int target,
               vector<int>& ds, vector<vector<int>>& ans) {
        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[i] <= target) {
            ds.push_back(candidates[i]);

            solve(i, candidates, target - candidates[i], ds, ans);

            ds.pop_back();
        }

        solve(i + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};