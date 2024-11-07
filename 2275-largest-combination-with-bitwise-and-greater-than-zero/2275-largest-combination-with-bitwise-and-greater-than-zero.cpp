class Solution {
public:
    int largestCombination(vector<int>& candidates) {


            int frq=0;


            for(int i=0;i<32;i++){
            

            int count=0;
            for(auto n:candidates){
                if(n&(1<<i)){
                    count++;
                }
            }
            frq=max(frq,count);
            }
            return frq;
        
    }
};