class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        int i = 0;
        while (i < logs.size()) {
            if (logs[i] != "../" && logs[i] != "./") {
                st.push(logs[i]);

            } else if (logs[i] == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            i++;
        }
        int ans = 0;
        while (!st.empty()) {
            ans += 1;
            st.pop();
        }
        return ans;
    }
};