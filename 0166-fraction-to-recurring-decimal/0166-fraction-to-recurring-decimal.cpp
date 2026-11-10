class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";

        string ans;

        // Check sign
        if ((numerator < 0) != (denominator < 0))
            ans += "-";

        // Convert to long long to avoid overflow
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Integer part
        ans += to_string(n / d);

        long long rem = n % d;

        if (rem == 0)
            return ans;

        ans += ".";

        unordered_map<long long, int> mp;

        while (rem != 0) {

            // Check repeating remainder
            if (mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            // Store remainder position
            mp[rem] = ans.length();

            rem *= 10;

            // Calculate next decimal digit
            ans += to_string(rem / d);

            rem %= d;
        }

        return ans;
    }
};