
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;

        for (string f : folder) {
            if (ans.empty() ||
                ans.back() != f.substr(0, ans.back().size()) ||
                f[ans.back().size()] != '/') {
                ans.push_back(f);
            }
        }

        return ans;
    }
};
