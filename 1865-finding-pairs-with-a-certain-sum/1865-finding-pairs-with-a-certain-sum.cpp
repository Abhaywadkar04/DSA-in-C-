class FindSumPairs {
    vector<int> n, m;
    unordered_map<int, int> freqM;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n = nums1;
        m = nums2;

        for (int num : m) {
            freqM[num]++;
        }
    }

    void add(int index, int val) {
        freqM[m[index]]--;           
        m[index] += val;            
        freqM[m[index]]++;       
    }

    int count(int tot) {
        int cnt = 0;
        for (int a : n) {
            int b = tot - a;
            cnt += freqM[b];
        }
        return cnt;
    }
};
