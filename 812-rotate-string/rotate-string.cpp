class Solution {
public:
    bool rotateString(string s, string goal) {

      

        for (int i = 0; i < s.length(); i++) {
            if (s == goal) {
                return true;
                break;
            }
            char first = s[0]; 
            s.erase(0, 1);     
            s.push_back(first);
        }
        return false;
    }
};