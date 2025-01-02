class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> sample;
        int count = 0;

        // Build the cumulative count array
        for (const string& word : words) {
            if (!word.empty()) {
                char first = tolower(word.front());
                char last = tolower(word.back());
                
                // Check if both first and last characters are vowels
                if ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
                    (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u')) {
                    sample.push_back(++count);
                } else {
                    sample.push_back(count);
                }
            }
        }

        vector<int> answer;

        // Process each query
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];

            if (left == 0) {
                answer.push_back(sample[right]);
            } else {
                answer.push_back(sample[right] - sample[left - 1]);
            }
        }

        return answer;
    }
};
