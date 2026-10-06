class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // 1. Ignore leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long ans = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {

            ans = ans * 10 + (s[i] - '0');

            // 4. Check overflow
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};