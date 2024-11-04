#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();

        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;

            // Count consecutive occurrences of word[i]
            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }

            // Append the character and its count in chunks if needed
            while (count > 0) {
                if (count > 9) {
                   
                    ans += "9";
                     ans += currentChar;
                    count -= 9;
                } else {
                    
                    ans += to_string(count);
                    ans += currentChar;
                    count = 0;
                }
            }
        }

        return ans;
    }
};
