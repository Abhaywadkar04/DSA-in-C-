class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;

        while (i < s.length()) {
            string temp = "";
            for (int j = 0; j < k; j++) {
                if (i < s.length()) {
                    temp += s[i++];
                } else {
                    temp += fill;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
