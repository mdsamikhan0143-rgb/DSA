
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string temp = num.substr(i, 3);

                if (temp > ans) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};
