class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int x : nums) {

            while (!st.empty()) {

                int g = gcd(st.back(), x);

                if (g == 1)
                    break;

                // Calculate LCM
                x = (st.back() / g) * x;

                st.pop_back();
            }

            st.push_back(x);
        }

        return st;
    }
};