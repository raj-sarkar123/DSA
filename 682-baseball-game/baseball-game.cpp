class Solution {
public:
    int calPoints(vector<string>& operations) {
        int i = 0;
        stack<int> st;
        while (i < operations.size()) {
            if (operations[i] != "+" && operations[i] != "D" &&
                operations[i] != "C") {
                int num = stoi(operations[i]);
                st.push(num);
            } else {
                if (operations[i] == "+") {
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    int sum = first + second;
                    st.push(first);
                    st.push(sum);
                } else if (operations[i] == "D") {

                    st.push(st.top() * 2);
                } else if (operations[i] == "C") {
                    st.pop();
                }
            }
            i++;
        }

        int ans = 0;
        while (!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};