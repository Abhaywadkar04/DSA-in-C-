class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m;
    for(int j=0;j<n;j++){
        nums1[k]=nums2[j];
        k++;
    }
    sort (nums1.begin(),nums1.end());

    }
};