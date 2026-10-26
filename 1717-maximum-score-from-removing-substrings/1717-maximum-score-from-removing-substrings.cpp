
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char &c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }

        string st;
        int ans = 0;

        for (char c : s) {
            if (c == 'b' && !st.empty() && st.back() == 'a') {
                st.pop_back();
                ans += x;
            } else {
                st.push_back(c);
            }
        }

        string temp;

        for (char c : st) {
            if (c == 'a' && !temp.empty() && temp.back() == 'b') {
                temp.pop_back();
                ans += y;
            } else {
                temp.push_back(c);
            }
        }

        return ans;
    }
};
