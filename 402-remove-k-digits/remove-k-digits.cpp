class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int i = 0;

        while (i < num.length()) {
            int n = num[i] - '0';

            while (!st.empty() && st.top() > n && k > 0) {
                st.pop();
                k--;  
            }

            st.push(n);
            i++;
        }

        // If k is still remaining, remove from the end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string res = "";

        while (!st.empty()) {
            res.push_back(st.top() + '0');
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int pos = 0;
        while (pos < res.length() && res[pos] == '0') {
            pos++;
        }

        res = res.substr(pos);

        if (res.empty()) {
            return "0";
        }

        return res;
    }
};