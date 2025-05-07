class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mpp;

        for (auto& row : responses) {
            set<string> s;
            for (auto& word : row) {
                s.insert(word);  // avoid duplicates within a row
            }
            for (auto& word : s) {
                mpp[word]++;
            }
        }

        string result = "";
        int maxCount = 0;

        for (auto& [word, count] : mpp) {
            if (count > maxCount) {
                maxCount = count;
                result = word;
            }
        }

        return result;
    }
};
