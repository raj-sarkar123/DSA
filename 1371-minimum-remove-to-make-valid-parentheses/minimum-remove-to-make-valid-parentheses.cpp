class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        stack<int> invalid;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
              if(!st.empty()){
                st.pop();
              }else{
                invalid.push(i);
              }
            }
            i++;
        }

        string res = "";

        for (int i = s.length()-1; i >= 0; i--) {

            bool skip = false;

            if (!st.empty() && st.top() == i) {
                skip = true;
                st.pop();
            }

            

            if (!invalid.empty() && invalid.top() == i) {
                skip = true;
                invalid.pop();
            }

            if (!skip) {
                res.push_back(s[i]);
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};