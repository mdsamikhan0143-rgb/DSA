
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string dir;

        while (getline(ss, dir, '/')) {

            if (dir == "" || dir == ".") {
                continue;
            }

            else if (dir == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            else {
                st.push(dir);
            }
        }

        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        if (result == "") {
            return "/";
        }

        return result;
    }
};
