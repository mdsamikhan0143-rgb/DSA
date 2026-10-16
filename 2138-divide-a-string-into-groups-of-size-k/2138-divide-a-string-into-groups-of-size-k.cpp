class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for (int i = 0; i < s.size(); i += k) {
            string group = s.substr(i, k);

            while (group.size() < k) {
                group += fill;
            }

            ans.push_back(group);
        }

        return ans;
    }
};