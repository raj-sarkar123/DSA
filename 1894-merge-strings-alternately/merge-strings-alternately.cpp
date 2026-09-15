class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string ans;
        int i = 0;

        while (i < s1.length() && i < s2.length()) {
            ans += s1[i];
            ans += s2[i];
            i++;
        }

        while (i < s1.length()) {
            ans += s1[i];
            i++;
        }

        while (i < s2.length()) {
            ans += s2[i];
            i++;
        }

        return ans;
    }
};