class Solution {
public:

    vector<string> ans;

    void solve(string &s, int index, int parts, string ip) {

        // Exactly 4 parts and all digits used
        if (parts == 4) {
            if (index == s.size()) {
                ip.pop_back();  // Remove last dot
                ans.push_back(ip);
            }
            return;
        }

        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string temp = s.substr(index, len);

            // Leading zero condition
            if (len > 1 && temp[0] == '0')
                break;

            int num = stoi(temp);

            // Value must be <= 255
            if (num > 255)
                break;

            // Include current segment
            solve(s, index + len, parts + 1, ip + temp + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "");

        return ans;
    }
};