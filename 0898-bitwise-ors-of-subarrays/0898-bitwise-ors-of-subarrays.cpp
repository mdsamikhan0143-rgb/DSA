
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st;
        set<int> curr;

        for (int num : arr) {
            set<int> next;

            next.insert(num);

            for (int x : curr) {
                next.insert(x | num);
            }

            curr = next;

            for (int x : curr) {
                st.insert(x);
            }
        }

        return st.size();
    }
};




