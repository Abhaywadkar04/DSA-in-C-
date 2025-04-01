class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int>dummy;
        int num = grid[0][0] % x;

        for(auto& row : grid){
            for(auto i : row){
                if(i % x != num) return -1;
                dummy.push_back(i);
            }
        }

        sort(dummy.begin(),dummy.end());

        int mid = dummy[dummy.size()/2];
        int count =0;

        for(auto i : dummy){
            count += abs(i-mid)/x;
        }
        return count;
    }
};