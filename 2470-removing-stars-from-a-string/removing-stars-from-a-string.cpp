class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res;
        int i = 0;
        while (i < s.length()) {

            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};