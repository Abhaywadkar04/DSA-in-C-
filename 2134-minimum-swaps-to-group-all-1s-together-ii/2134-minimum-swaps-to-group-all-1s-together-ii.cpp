class Solution {
public:
    int minSwaps(vector<int>& nums) {

         int count = 0;
        int n = nums.size();

        // Count the number of 1s in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            }
        }



        if( count == 1 || count == 0){
            return 0;
        }

        int currentOnes=0;

        for(int i=0;i<count;i++){
            currentOnes = currentOnes + nums[i];
        }

      

        int maxOnes=currentOnes;
        for (int i = 0; i < n; i++) {
            currentOnes -= nums[i];
            currentOnes += nums[(i + count) % n];
            maxOnes = max(maxOnes, currentOnes);
        }
        
        return count - maxOnes;
    }
    
};