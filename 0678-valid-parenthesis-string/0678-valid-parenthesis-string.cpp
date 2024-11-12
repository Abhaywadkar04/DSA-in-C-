#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                minOpen += 1;
                maxOpen += 1;
            } else if (s[i] == ')') {
                minOpen -= 1;
                maxOpen -= 1;
            } else { // s[i] == '*'
                minOpen -= 1;
                maxOpen += 1;
            }

            if (minOpen < 0) minOpen = 0;
            if (maxOpen < 0) return false;
        }

        return minOpen == 0;
    }
};
