
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxi = s;
        string mini = s;

        // Find maximum number
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                char ch = s[i];

                for (int j = 0; j < s.size(); j++) {
                    if (maxi[j] == ch) {
                        maxi[j] = '9';
                    }
                }
                break;
            }
        }

        // Find minimum number
        char ch = s[0];

        if (ch != '1') {
            for (int i = 0; i < s.size(); i++) {
                if (mini[i] == ch) {
                    mini[i] = '1';
                }
            }
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (mini[i] != '0' && mini[i] != '1') {
                    char ch = mini[i];

                    for (int j = 1; j < s.size(); j++) {
                        if (mini[j] == ch) {
                            mini[j] = '0';
                        }
                    }
                    break;
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
