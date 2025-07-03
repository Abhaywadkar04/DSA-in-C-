class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.size() < k) {
            string dummy = "";

            for (int i = 0; i < word.size(); i++) {
                dummy += word[i] + 1;  
            }

            word += dummy;
        }

        return word[k - 1];  
    }
};
