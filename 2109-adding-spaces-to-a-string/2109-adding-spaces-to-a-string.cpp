class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spaceIndex = 0; // Pointer for the spaces vector
        
        for (int i = 0; i < s.length(); ++i) {
            // Check if the current index matches the next space position
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' '; // Add a space
                ++spaceIndex;  // Move to the next space index
            }
            result += s[i]; // Add the current character
        }
        
        return result;
    }
};
