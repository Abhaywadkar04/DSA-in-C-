
class Solution {
public:
    int countSeniors(vector <string>& details) {
        vector<int> arr; // Declare a vector to store the values

        for(int i = 0; i < details.size(); i++) {
            
            string ans = details[i].substr(11, 2);
            int value = stoi(ans);
            if(value > 60) {
                arr.push_back(value); // Add value to the vector if it meets the condition
            }
        }

        return arr.size(); // Return the size of the vector
    }
};
