class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string ans;
        int m = 0;
       
        int mini = min(s1.length(), s2.length());
        while (m < mini) {
            ans.push_back(s1[m]);
            ans.push_back(s2[m]);
            m++;
        }
        string longest;
        if (s1.length() > s2.length()) {

            longest = s1;
        } else {

            longest = s2;
        }
        for (int i = m; i < longest.length(); i++) {
            ans.push_back(longest[i]);
        }
        return ans;
    }
};