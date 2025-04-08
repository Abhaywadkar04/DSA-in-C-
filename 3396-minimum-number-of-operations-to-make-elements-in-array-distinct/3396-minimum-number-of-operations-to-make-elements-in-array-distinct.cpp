class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>map;

        int count=0;
        int k =0;
        int i =0;
       while(i<nums.size()){

            map[nums[i]]++;

            if(map[nums[i]]>1){
                k+=3;
                i=k;
                map.clear();
                count++;
            }
            else{
                i++;
            }

       }
       return count;
    }
};