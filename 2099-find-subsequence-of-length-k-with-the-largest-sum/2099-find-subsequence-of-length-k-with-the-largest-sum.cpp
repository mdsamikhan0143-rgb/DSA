
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.rbegin(), arr.rend());

        vector<pair<int, int>> temp;

        for (int i = 0; i < k; i++) {
            temp.push_back(arr[i]);
        }

        sort(temp.begin(), temp.end(),
             [](auto a, auto b) {
                 return a.second < b.second;
             });

        vector<int> ans;

        for (auto p : temp) {
            ans.push_back(p.first);
        }

        return ans;
    }
};
