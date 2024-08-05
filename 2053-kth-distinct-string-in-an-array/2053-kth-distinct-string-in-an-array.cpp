class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>counter;

        for(int i=0;i<arr.size();i++){
            counter[arr[i]]++;
        }

        for(auto v : arr){
            if(counter[v]==1){
                --k;
                if(k==0)return v;
            }
        }

        return "";
    }

};