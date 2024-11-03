

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string m = s + s;
        return m.find(goal) != string ::npos;
    }
};
