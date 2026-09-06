class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string res;

        int i=0;
        while(i<s.length()){
            if(!st.empty() && abs(s[i]-st.top())==32){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};