class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int>array=arr;
        sort(array.begin(),array.end());
        array.erase(std::unique(array.begin(), array.end()), array.end());
        unordered_map<int,int>map;


        for(int i=0;i<array.size();i++){
            map[array[i]]=i+1;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=map[arr[i]];
        }


return arr;
        
    }
};