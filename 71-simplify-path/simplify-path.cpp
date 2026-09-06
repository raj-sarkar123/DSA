class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string current = "";

        for (int i = 0; i <= path.length(); i++) {
            if (i == path.length() || path[i] == '/') {
                if (current == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else if (current != "" && current != ".") {
                    st.push(current);
                }
                current = "";
            } else {
                current += path[i];
            }
        }

        string res = "";
        while (!st.empty()) {
            res = '/' + st.top() + res;
            st.pop();
        }
        // reverse(res.begin(), res.end());
        return res.empty() ? "/" : res;
    }
};