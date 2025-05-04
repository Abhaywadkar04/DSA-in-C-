class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mpp;
        int count = 0;

        for (int i = 0; i < dominoes.size(); i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            if (a > b) swap(a, b);  

            pair<int, int> key = {a, b};
            count += mpp[key];  
            mpp[key]++;
        }

        return count;
    }
};
