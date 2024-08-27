

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false; 
        }

        // Sort both strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

   
        return s == t;
    }
};
