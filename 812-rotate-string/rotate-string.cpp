class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) {
            return false;
        }

        string concatinated = s + s;

        return (concatinated.find(goal) == string::npos) ? false : true;
    }
};