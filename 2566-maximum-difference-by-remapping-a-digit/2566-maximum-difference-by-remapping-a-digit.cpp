
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string maxi = s;
        string mini = s;

        // Make maximum number
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

        // Make minimum number
        char ch = s[0];

        for (int i = 0; i < s.size(); i++) {
            if (mini[i] == ch) {
                mini[i] = '0';
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
