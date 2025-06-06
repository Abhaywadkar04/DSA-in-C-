class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        set<int> s;
        for (int i = 0; i < arr.size(); i++) {
            s.insert(arr[i]);  
        }

        if (s.size() < 2) return -1;

        vector<int> newarr(s.begin(), s.end());

        sort(newarr.begin(), newarr.end(), greater<int>());

        return newarr[1]; 
    }
};
