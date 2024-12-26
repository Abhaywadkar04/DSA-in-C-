class Solution {
public:
    vector<int> arr;
    void run(int id,int &target,int &c,int sum){
        if(id==arr.size()){
            if(target==sum){
                c++;
            }

            return;
        }

        run(id+1,target,c,sum-arr[id]);
        run(id+1,target,c,sum+arr[id]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int c=0;
        arr.resize(nums.size());
        arr=nums;
        run(0,target,c,0);

        return c;
    }
};