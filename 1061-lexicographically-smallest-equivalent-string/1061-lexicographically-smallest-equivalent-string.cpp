class Solution {
    int find(vector<int>& carr, int s) {
        if (carr[s] == s) return s;
        return carr[s] = find(carr, carr[s]); 
    }
    
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> carr(26);
        for (int i = 0; i < 26; i++) {
            carr[i] = i; 
        }

        for (int i = 0; i < s1.size(); i++) {
            int x = find(carr, s1[i] - 'a');
            int y = find(carr, s2[i] - 'a');

            if (x == y) continue;
            if (x < y) carr[y] = x;
            else carr[x] = y;
        }

        string ans;
        for (char ch : baseStr) {
            int parent = find(carr, ch - 'a');
            ans.push_back(parent + 'a');
        }

        return ans;
    }
};
