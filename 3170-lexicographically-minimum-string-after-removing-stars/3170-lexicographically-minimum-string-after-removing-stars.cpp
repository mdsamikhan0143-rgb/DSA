class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<bool> removed(n, false);
        vector<int> pos[26];

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removed[i] = true;

                for (int j = 0; j < 26; j++) {
                    if (!pos[j].empty()) {
                        removed[pos[j].back()] = true;
                        pos[j].pop_back();
                        break;
                    }
                }
            } 
            else {
                pos[s[i] - 'a'].push_back(i);
            }
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};