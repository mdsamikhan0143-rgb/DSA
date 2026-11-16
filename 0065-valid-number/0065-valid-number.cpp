class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                digit = true;
            }

            else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }

            else if (s[i] == '.') {
                if (dot || exp) {
                    return false;
                }
                dot = true;
            }

            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !digit) {
                    return false;
                }

                exp = true;
                digit = false;
            }

            else {
                return false;
            }
        }

        return digit;
    }
};